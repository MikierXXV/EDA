#include "Player.hh"
/*#include "Settings.hh"
#include "Structs.hh"
#include "State.hh"
#include <vector>
#include <queue>
#include <map>*/

/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME NewRome


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */

  const vector<Dir> dirs = {TOP,BOTTOM,RIGHT,LEFT};
  typedef pair<Pos, bool> Position;
  typedef pair<Dir, bool> Direction;
  typedef vector<vector<Position>> Steps;
  typedef map<int,int> my_troops;
  typedef map<int,int>::iterator Iterator;
  typedef pair<int, int> ady; //first = dist, second = ciudad adyacente
  struct Ciudad {
    int tam;
    bool mia;
    bool hay_alguien;
    priority_queue<ady, vector<ady>, greater<ady>> adyacentes;
  };
  

  //Encontrar direccion
  Dir find_direction(Steps& S, Pos ini, Pos fin){
    if (S[fin.i][fin.j].first == ini){
      if (fin.i == ini.i){
        if(fin.j == ini.j -1) return LEFT;
        else return RIGHT;
      }
      else {
        if (fin.i == ini.i -1) return TOP;
        else return BOTTOM;
      }
    }
    else return find_direction(S, ini, S[fin.i][fin.j].first);
  }

  //retorna direccion opuesta
  Dir opposite(Dir d){
    if (d == TOP) return BOTTOM;
    else if (d == BOTTOM) return TOP;
    else if (d == LEFT) return RIGHT;
    else if (d == RIGHT) return LEFT;
    else return d;
  }


//Buscar ciudad
Direction search_city(Pos p){
  int N = rows();
  int M = cols();
  Steps S (N, vector<Position>(M, {{-1,-1}, false}));

  bool city = false;
  Dir city_dir = TOP;

  queue<Pos> q;
  q.push(p);
  S[p.i][p.j].second = true;

  while (not city and not q.empty()){
    Pos p2 = q.front();
    q.pop();
    for (Dir d : dirs){
      //and cell(p2+d).virus == 0 tener en cuenta infeccion virus en la busqueda de la ciudad
      if (not city and pos_ok(p2+d) and cell(p2+d).type != WALL
      and not S[(p2+d).i][(p2+d).j].second){
        if (cell(p2+d).type == CITY and city_owner(cell(p2+d).city_id) != me()){
          city = true;
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          city_dir = find_direction(S, p, p2+d);
        }
        else if((p2 == p and cell(p2+d).unit_id == -1) or (p2 != p)) {
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          q.push(p2+d);
        }
      }
    }
  }
  return {city_dir, city};
}

//Retorna true si ciudad sin jugadores enemigos, false otherwise
bool city_vacia(int id_city){
  bool res = true;
  //City c = city(id_city);
  //for (Pos p : c){
    if (city_owner(id_city) != -1) res = false;
  //}
  return res;
}


//Retorna true si la ciudad vacia y conquistada por otro player, false otherwise
bool city_vacia_conquistada(int id_city){
  bool res = city_owner(id_city) != me();
  City c = city(id_city);
  int cont  = 0;
  for (Pos p : c){
    //and unit(cell(p).unit_id).player != me()
    if (cell(p).unit_id != -1 and unit(cell(p).unit_id).player != me()) ++cont;
  }
  return (cont <= 1);
}

Direction search_city_vacia(Pos p){
  int N = rows();
  int M = cols();
  Steps S (N, vector<Position>(M, {{-1,-1}, false}));

  bool city = false;
  Dir city_dir = TOP;

  queue<Pos> q;
  q.push(p);
  S[p.i][p.j].second = true;

  while (not city and not q.empty()){
    Pos p2 = q.front();
    q.pop();
    for (Dir d : dirs){
      //and cell(p2+d).virus == 0 tener en cuenta infeccion virus en la busqueda de la ciudad
      if (not city and pos_ok(p2+d) and (p2 != p or (p2 == p and cell(p2+d).unit_id == -1)) and cell(p2+d).type != WALL
      and not S[(p2+d).i][(p2+d).j].second){
        if (cell(p2+d).type == CITY and city_owner(cell(p2+d).city_id) != me() and 
        ((round() >= 10 and city_vacia_conquistada(cell(p2+d).city_id)) or (round() < 10 and city_vacia(cell(p2+d).city_id)))) {
          city = true;
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          city_dir = find_direction(S, p, p2+d);
        }
        else if((p2 == p and cell(p2+d).unit_id == -1) or (p2 != p)){
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          q.push(p2+d);
        }
      }
    }
  }
  return {city_dir, city};
}


//Retorna true si el path vacio y conquistado por otro player, false otherwise
bool path_vacio_conquistado(int id_path){
  bool res = path_owner(id_path) != me();
  Path pa = path(id_path);
  for (Pos p : pa.second){
    if (cell(p).unit_id != -1 and unit(cell(p).unit_id).player != me()) res = false;
  }
  return res;
}

//Buscar path
Direction search_path(Pos p){
  int N = rows();
  int M = cols();
  Steps S (N, vector<Position>(M, {{-1,-1}, false}));

  bool path = false;
  Dir path_dir = TOP;

  queue<Pos> q;
  q.push(p);
  S[p.i][p.j].second = true;

  while (not path and not q.empty()){
    Pos p2 = q.front();
    q.pop();
    for (Dir d : dirs){
      //and cell(p2+d).virus == 0 tener en cuenta infeccion virus en la busqueda de la ciudad
      if (not path and pos_ok(p2+d) and cell(p2+d).type != WALL
      and not S[(p2+d).i][(p2+d).j].second){
        if (cell(p2+d).type == PATH and path_owner(cell(p2+d).path_id) != me()){
          path = true;
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          path_dir = find_direction(S, p, p2+d);
        }
        else if((p2 == p and cell(p2+d).unit_id == -1) or (p2 != p)){
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          q.push(p2+d);
        }
      }
    }
  }
  return {path_dir, path};
}


//Retorna true si ciudad contaminada, false otherwise
bool city_contaminada(int id_city){
  bool res = false;
  City c = city(id_city);
  for (Pos p : c){
    if (cell(p).virus > 0) res = true;
  }
  return res;
}


//Buscar ciudad en concreto WORKING
Direction search_city_id(Pos p, int id_city){
  int N = rows();
  int M = cols();
  Steps S (N, vector<Position>(M, {{-1,-1}, false}));

  bool city = false;
  Dir city_dir = TOP;

  queue<Pos> q;
  q.push(p);
  S[p.i][p.j].second = true;

  while (not city and not q.empty()){
    Pos p2 = q.front();
    q.pop();
    for (Dir d : dirs){
      //and cell(p2+d).virus == 0 mirar si ciudad no infectada
      if (not city and pos_ok(p2+d) and cell(p2+d).type != WALL 
      and not S[(p2+d).i][(p2+d).j].second){
        if (cell(p2+d).city_id == id_city){
          city = true;
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          city_dir = find_direction(S, p, p2+d);
        }
        else if ((p2 == p and cell(p2+d).unit_id == -1) or (p2 != p)) {
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          q.push(p2+d);
        }
      }
    }
  }
  return {city_dir, city};
}

//Busco enemigo
Direction search_enemy(Pos p){
  int N = rows();
  int M = cols();
  Steps S (N, vector<Position>(M, {{-1,-1}, false}));

  bool enemy = false;
  Dir enemy_dir = TOP;
  int myteam = me();

  queue<Pos> q;
  q.push(p);
  S[p.i][p.j].second = true;

  while (not enemy and not q.empty()){
    Pos p2 = q.front();
    q.pop();
    for (Dir d : dirs){
      if (not enemy and pos_ok(p2+d) and cell(p2+d).type != WALL and not S[(p2+d).i][(p2+d).j].second){
        int ide = cell(p2+d).unit_id;
        if (ide != -1 and unit(ide).player != myteam){
          enemy = true;
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          enemy_dir = find_direction(S, p, p2+d);
        }
        else if((p2 == p and cell(p2+d).unit_id == -1) or (p2 != p)) {
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          q.push(p2+d);
        }
      }
    }
  }
  return {enemy_dir, enemy};
}

//Busco enemigo en ciudad
Direction search_enemy_city(Pos p){
  int N = rows();
  int M = cols();
  Steps S (N, vector<Position>(M, {{-1,-1}, false}));

  bool enemy = false;
  Dir enemy_dir = TOP;
  int myteam = me();

  queue<Pos> q;
  q.push(p);
  S[p.i][p.j].second = true;

  while (not enemy and not q.empty()){
    Pos p2 = q.front();
    q.pop();
    for (Dir d : dirs){
      if (not enemy and pos_ok(p2+d) and cell(p2+d).type != WALL 
       and not S[(p2+d).i][(p2+d).j].second and cell(p2+d).type == CITY){
        int ide = cell(p2+d).unit_id;
        if (ide != -1 and unit(ide).player != myteam){
          enemy = true;
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          enemy_dir = find_direction(S, p, p2+d);
        }
        else if((p2 == p and cell(p2+d).unit_id == -1) or (p2 != p)) {
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          q.push(p2+d);
        }
      }
    }
  }
  return {enemy_dir, enemy};
}

//Busco enemigo en path
Direction search_enemy_path(Pos p){
  int N = rows();
  int M = cols();
  Steps S (N, vector<Position>(M, {{-1,-1}, false}));

  bool enemy = false;
  Dir enemy_dir = TOP;
  int myteam = me();

  queue<Pos> q;
  q.push(p);
  S[p.i][p.j].second = true;

  while (not enemy and not q.empty()){
    Pos p2 = q.front();
    q.pop();
    for (Dir d : dirs){
      if (not enemy and pos_ok(p2+d) and cell(p2+d).type != WALL 
       and not S[(p2+d).i][(p2+d).j].second and cell(p2+d).type == PATH){
        int ide = cell(p2+d).unit_id;
        if (ide != -1 and unit(ide).player != myteam){
          enemy = true;
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          enemy_dir = find_direction(S, p, p2+d);
        }
        else if((p2 == p and cell(p2+d).unit_id == -1) or (p2 != p)) {
          S[(p2+d).i][(p2+d).j].second = true;
          S[(p2+d).i][(p2+d).j].first = p2;
          q.push(p2+d);
        }
      }
    }
  }
  return {enemy_dir, enemy};
}



//Ver enemigos y aliados en una ciudad
pair<int, int> recount_units_city(int id_city){
  City c = city(id_city);
  int enemies = 0, alies = 0;
  for (Pos p : c){
    if (cell(p).unit_id != -1) {
      Unit u = unit(cell(p).unit_id);
      if (u.player != me()) ++enemies;
      else if (u.player == me()) ++alies;
    }
  }
  return{enemies, alies};
}

//Ver enemigos y aliados en una ciudad
pair<int, int> recount_units_path(int id_path){
  Path pat = path(id_path);
  int enemies = 0, alies = 0;
  for (Pos p : pat.second){
    if (cell(p).unit_id != -1) {
      Unit u = unit(cell(p).unit_id);
      if (u.player != me()) ++enemies;
      else if (u.player == me()) ++alies;
    }
  }
  return{enemies, alies};
}

//Ver si aliados en ciudad 
//retorna map de las unidades que estan en una ciudad 
my_troops exisit_my_unit_in_city(const vector<Ciudad>& id_city, const vector<int>& id_unit){
  my_troops m;
  //busco en cada ciudad mis unidades y si no estaban las inserto en el map con su ciudad y si estaban ya en el map 
  //pero ahora se encuentran en una ciudad le asigno esa ciudad
  for (int i = 0; i < int(id_city.size()); ++i){
    City c = city(i);
    for (Pos p : c){
      if (cell(p).unit_id != -1 and unit(cell(p).unit_id).player == me()){
        m.insert({cell(p).unit_id, i});
      }
    }
  }
  return m;
}

//Numero de unidades alidas infectadas
int num_my_units_infected(const vector<int>& u){
  int num_infectados = 0;
  for (int i = 0; i < int(u.size()); ++i){
    Unit un = unit(u[i]);
    if (un.damage > 0) ++num_infectados;
  }
  return num_infectados;
}


bool ciudad_vacia_id(const vector<int>& c, int id_city){
  for (int i = 0; i < int(c.size()); ++i){
    if (c[i] == id_city) return true;
  }
  return false;
}

//Para unidad devuelve la city donde esta
int unit_in_city(my_troops& m, int id_unit){
  Iterator it = m.find(id_unit);
  return it->second;
}

int tamano_ciudad(int id_city, const vector<Ciudad>& c){
  return c[id_city].tam;
}

//retorna adyecentes de una ciudad
priority_queue<ady, vector<ady>, greater<ady>> cities_adyecentes(int id_city, const vector<Ciudad>& c){
  return c[id_city].adyacentes;

}


  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    //identificadores mis unidades
    vector<int> u = my_units(me());
    int num_myunit_infe = num_my_units_infected(u);
    //identificadores ciudades
    vector<Ciudad> c(nb_cities());
    vector<int> ciudades_vacias;
    vector<int> ciudades_vacias_con;
    vector<pair<int,int>> unidades_ciudades;
    int ciudad_max = 0;
    for (int i = 0; i < nb_cities(); ++i){
      City ci = city(i);
      c[i].tam = ci.size();
      c[i].mia = city_owner(i);
      if(city_vacia(i)) ciudades_vacias.push_back(i);
      if(city_vacia_conquistada(i)) ciudades_vacias_con.push_back(i);
      if (c[ciudad_max].tam < c[i].tam) ciudad_max = i;
      pair<int,int> estatus = recount_units_city(i);
      unidades_ciudades.push_back(estatus);
    }
   
    for (int i = 0; i < nb_paths(); ++i){
      Path p = path(i);
      int ciu_ori = p.first.first;
      int ciu_dest = p.first.second;
      int tam = p.second.size();
      c[ciu_ori].adyacentes.push({tam, ciu_dest});
    }
    
    //inversa amb unitat y ciutat
    my_troops m = exisit_my_unit_in_city(c, u);
    vector<int> contadores_unidades(nb_cities(),0);
    int cont_uni_max = 0;

    //por cada unidad
    for (int id : u){
      Pos p1 = unit(id).pos;
      int my_id = me();
      bool enciudad = cell(p1).city_id != -1;

      //mirar alrededor
      bool mueve = false;
      for (Dir d: dirs){
        if (pos_ok(p1+d) and cell(p1+d).type != WALL) {
          if ((cell(p1+d).unit_id != -1  and unit(cell(p1+d).unit_id).player != me())) { 
            /*if (unit(id).health - unit(cell(p1+d).unit_id).health < 10){
              Dir d1 = opposite(d);
              if (pos_ok(p1+d1) and cell(p1+d1).type != WALL){
                move(id, d1);
                mueve = true;
                break;
              }
            }*/
            //else {
              move(id, d);
              mueve = true;
              break;
            //}
          }
         /* else if (cell(p1+d).type == CITY and city_owner(cell(p1+d).city_id) != me()){
            move(id, d);
            mueve = true;
            break;
          }*/
          else if (cell(p1+d).type == PATH and path_owner(cell(p1+d).path_id) != me()){
            move(id, d);
            mueve = true;
            break;
          }
          else if (cell(p1+d).mask and not unit(id).immune and not unit(id).mask){
            move(id, d);
            mueve = true;
            break;
          }
        }
      }
    /*  if (not mueve) {
        if (city_vacia_conquistada(ciudad_max) and cont_uni_max < 4) {
            //Direction d1 = search_city_vacia(p1);
            Direction d1 = search_city_id(p1, ciudad_max);
            if(d1.second){
              move(id, d1.first);
              mueve = true;
              ++cont_uni_max;
            } 
        }
      }*/
      if (not mueve){
        bool enciudad = cell(p1).city_id != -1;
        bool enpath = cell(p1).path_id != -1;
        if (not enciudad and not enpath){
          if(ciudades_vacias_con.size() > 0 or ciudades_vacias.size() > 0){
            Direction d1 = search_city_vacia(p1);
            //Direction d1 = search_city_id(p1, ciudad_max);
            if(d1.second){
              move(id, d1.first);
            } 
          }
          else {
            Direction d1 = search_city(p1);
            if(d1.second){
              move(id, d1.first);
            } 
          }
        }
        else if (enciudad) {
          int city_act = cell(p1).city_id;
          if (unidades_ciudades[city_act].first  == 1){
            Direction d = search_enemy_city(p1);
            if(d.second){
              move(id, d.first);
            } 
          }
          else {
            Direction d = search_path(p1);
            if(d.second){
              move(id, d.first);
            } 
          }
        }
        else {
          if(ciudades_vacias_con.size() > 0){
            Direction d1 = search_city_vacia(p1);
            //Direction d1 = search_city_id(p1, ciudad_max);
            if(d1.second){
              move(id, d1.first);
            } 
          }
          else {
            Direction d1 = search_city(p1);
            if(d1.second){
              move(id, d1.first);
            } 
          }
        }
        /*
        if (not enciudad and not enpath){
          if(ciudades_vacias_con.size() > 0){
            Direction d1 = search_city_vacia(p1);
            //Direction d1 = search_city_id(p1, ciudad_max);
            if(d1.second){
              move(id, d1.first);
            } 
          }
          else {
            Direction d1 = search_city(p1);
            if(d1.second){
              move(id, d1.first);
            } 
          }
        }
        else if(enciudad and city_owner(cell(p1).city_id) == me()){
          int city_act = cell(p1).city_id;
          //si hay ciudad adyacente voy
          priority_queue<ady, vector<ady>, greater<ady>> city_ady = cities_adyecentes(city_act, c);
          if (not city_ady.empty() and city_owner(city_ady.top().second) != me()){
            Direction d = search_city_id(p1, city_ady.top().second);
            if(d.second){
              move(id, d.first);
            }
          }
          else if (city_ady.empty()){
            if(ciudades_vacias_con.size() > 0){
              Direction d1 = search_city_vacia(p1);
              //Direction d1 = search_city_id(p1, ciudad_max);
              if(d1.second){
                move(id, d1.first);
              } 
            }
          }
          else {
            Direction d1 = search_path(p1);
            if(d1.second){
              move(id, d1.first);
            } 
            else{
              Direction d1 = search_city(p1);
              if(d1.second){
                move(id, d1.first);
              } 
            }
          }
          Direction d1 = search_path(p1);
          if(d1.second){
            move(id, d1.first);
          } 
          else{
            Direction d1 = search_city(p1);
            if(d1.second){
              move(id, d1.first);
            } 
          }
        }
        else if(enciudad and city_owner(cell(p1).city_id) != me()){
          int city_act = cell(p1).city_id;
          if (unidades_ciudades[city_act].first - unidades_ciudades[city_act].second >= 2){
            Direction d = search_path(p1);
            if(d.second){
              move(id, d.first);
            } 
          }
          else {
            Direction d = search_enemy_city(p1);
            if(d.second){
              move(id, d.first);
            } 
          }
        }
        else if(enpath){
          Path pat = path(cell(p1).path_id);
          int id_city_origen = pat.first.first;
          int id_city_desti = pat.first.second;
          if(city_owner(id_city_origen) == me()){
            if (path_owner(cell(p1).path_id) == me()){
              Direction d1 = search_city_id(p1, id_city_desti);
              if(d1.second){
                move(id, d1.first);
              } 
            }
            else{
              Direction d1 = search_enemy_path(p1);
              if(d1.second){
                move(id, d1.first);
              } 
            }
          }
          else if(city_owner(id_city_desti) == me()){
            if (path_owner(cell(p1).path_id) == me()){
              Direction d1 = search_city_id(p1, id_city_origen);
              if(d1.second){
                move(id, d1.first);
              } 
            }
            else{
              Direction d1 = search_enemy_path(p1);
              if(d1.second){
                move(id, d1.first);
              } 
            }
          }
          else if(city_owner(id_city_desti) == me() and city_owner(id_city_origen) == me()){
            if (path_owner(cell(p1).path_id) == me()){
              pair<int, int> par = recount_units_path(cell(p1).path_id);
              if(ciudades_vacias_con.size() > 0){
                Direction d1 = search_city_vacia(p1);
                if(d1.second){
                  move(id, d1.first);
                } 
              }
              else if (par.first == 1){
                Direction d1 = search_enemy_path(p1);
                if(d1.second){
                  move(id, d1.first);
                } 
              }
              else {
                Direction d1 = search_city(p1);
                if(d1.second){
                  move(id, d1.first);
                } 
              }
            }
            else if(city_owner(id_city_desti) != me() and city_owner(id_city_origen) != me()){
              pair<int, int> par = recount_units_path(cell(p1).path_id);
              if (path_owner(cell(p1).path_id) == me()){
                //en vez de tamaño por numero de enemigos posibilidad
                if (c[id_city_desti].tam >= c[id_city_origen].tam){
                  Direction d1 = search_city_id(p1, id_city_desti);
                  if(d1.second){
                    move(id, d1.first);
                  } 
                }
                else {
                  Direction d1 = search_city_id(p1, id_city_origen);
                  if(d1.second){
                    move(id, d1.first);
                  }
                }
              }
              else if (path_owner(cell(p1).path_id) != me()){
                if (par.first - par.second >= 2){
                  if(ciudades_vacias_con.size() > 0){
                    Direction d1 = search_city_vacia(p1);
                    //Direction d1 = search_city_id(p1, ciudad_max);
                    if(d1.second){
                      move(id, d1.first);
                    } 
                  }
                  else {
                    Direction d1 = search_city(p1);
                    if(d1.second){
                      move(id, d1.first);
                    } 
                  }
                }
              }
              else{
                if(ciudades_vacias_con.size() > 0){
                  Direction d1 = search_city_vacia(p1);
                  //Direction d1 = search_city_id(p1, ciudad_max);
                  if(d1.second){
                    move(id, d1.first);
                  } 
                }
                else {
                  Direction d1 = search_city(p1);
                  if(d1.second){
                    move(id, d1.first);
                  } 
                }
              }
            }
          }
        }*/
      }
    }
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
