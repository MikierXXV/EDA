#include "Player.hh"
#include <set>


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Andiamo


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
  const vector<NutrientType> nutrients = {Carbohydrate, Protein, Lipid};
  const vector<Dir> dirs = {Up,Down,Left,Right};
  typedef pair<Pos, bool> Posicion;
  typedef pair<Dir, bool> Direccion;
  typedef vector<vector<Posicion>> Pasos;
  // crear set marcadas 
  set<Pos> marcadas;

  bool pos_marcada(Pos p){
    set<Pos>::iterator it = marcadas.find(p);
    if (it != marcadas.end()) return true;
    else return false;
  }

  void anadir_marca(Pos p){
    set<Pos>::iterator it = marcadas.find(p);
    if (it == marcadas.end()) marcadas.insert(p);
  }

  void borrar_marca(Pos p){
    set<Pos>::iterator it = marcadas.find(p);
    if (it != marcadas.end()) marcadas.erase(it);
  }

  Dir encontrar_direccion (Pasos& P, Pos ini, Pos fin) {
	if (P[fin.i][fin.j].first == ini) {
		if (fin.i == ini.i) {
			if (fin.j == ini.j - 1) return Left;
			else return Right;
		}
		else {
			if (fin.i == ini.i - 1) return Up;
			else return Down;
		}
	}
	else return encontrar_direccion(P, ini, P[fin.i][fin.j].first);
}
  Direccion buscar_pipa(Pos p, int id_reina){
      //declaro medidas tablero
      int N = board_rows();
      int M = board_cols();
      //declaro tablero de pasos
      Pasos P(N, vector<Posicion>(M, {{-1,-1},false}));
      bool pipa_trobat = false;
      queue<Pos> q;
      //direccion donde esta la comida
      Dir pipa_dir = Up;
      q.push(p);
      P[p.i][p.j].second = true;
      while (not pipa_trobat and not q.empty()){
          Pos p2 = q.front();
          q.pop();
          for (Dir d : dirs){
              if(not pipa_trobat and pos_ok(p2+d) and cell(p2+d).id == -1 and 
              cell(p2+d).type != Water and not P[(p2+d).i][(p2+d).j].second
              and not pos_marcada(p2+d)){
                  if(cell(p2+d).bonus == Seed and not cerca_reina(p2+d, id_reina)){
                      pipa_trobat = true;
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2;
                      pipa_dir = encontrar_direccion(P, p, p2+d);
                  }
                  else {
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2;
                      q.push(p2+d);
                  }
              }
          }
      }
      return {pipa_dir, pipa_trobat};
  }

  Direccion buscar_hoja(Pos p, int id_reina){
      //declaro medidas tablero
      int N = board_rows();
      int M = board_cols();
      //declaro tablero de pasos
      Pasos P(N, vector<Posicion>(M, {{-1,-1},false}));
      bool hoja_trobat = false;
      queue<Pos> q;
      //direccion donde esta la comida
      Dir hoja_dir = Up;
      q.push(p);
      P[p.i][p.j].second = true;
      while (not hoja_trobat and not q.empty()){
          Pos p2 = q.front();
          q.pop();
          for (Dir d : dirs){
              if(not hoja_trobat and pos_ok(p2+d) and cell(p2+d).id == -1 and 
              cell(p2+d).type != Water and not P[(p2+d).i][(p2+d).j].second
              and not pos_marcada(p2+d)){
                  if(cell(p2+d).bonus == Leaf and not cerca_reina(p2+d, id_reina)){
                      hoja_trobat = true;
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2;
                      hoja_dir = encontrar_direccion(P, p, p2+d);
                  }
                  else {
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2;
                      q.push(p2+d);
                  }
              }
          }
      }
      return {hoja_dir, hoja_trobat};
  }

  Direccion buscar_pan(Pos p, int id_reina){
      //declaro medidas tablero
      int N = board_rows();
      int M = board_cols();
      //declaro tablero de pasos
      Pasos P(N, vector<Posicion>(M, {{-1,-1},false}));
      bool pan_trobat = false;
      queue<Pos> q;
      //direccion donde esta la comida
      Dir pan_dir = Up;
      q.push(p);
      P[p.i][p.j].second = true;
      while (not pan_trobat and not q.empty()){
          Pos p2 = q.front();
          q.pop();
          for (Dir d : dirs){
              if(not pan_trobat and pos_ok(p2+d) and cell(p2+d).id == -1 and 
              cell(p2+d).type != Water and not P[(p2+d).i][(p2+d).j].second
              and not pos_marcada(p2+d)){
                  if(cell(p2+d).bonus == Bread and not cerca_reina(p2+d, id_reina)){
                      pan_trobat = true;
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2;
                      pan_dir = encontrar_direccion(P, p, p2+d);
                  }
                  else {
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2;
                      q.push(p2+d);
                  }
              }
          }
      }
      return {pan_dir, pan_trobat};
  }
  
  Direccion buscar_comida(Pos p, int id_reina){
      //declaro medidas tablero
      int N = board_rows();
      int M = board_cols();
      //declaro tablero de pasos
      Pasos P(N, vector<Posicion>(M, {{-1,-1},false}));
      bool comida_trobat = false;
      queue<Pos> q;
      //direccion donde esta la comida
      Dir comida_dir = Up;
      q.push(p);
      P[p.i][p.j].second = true;
      while (not comida_trobat and not q.empty()){
          Pos p2 = q.front();
          q.pop();
          for (Dir d : dirs){
              if(not comida_trobat and pos_ok(p2+d) and cell(p2+d).id == -1 and 
              cell(p2+d).type != Water and not P[(p2+d).i][(p2+d).j].second
              and not pos_marcada(p2+d)){
                  if(cell(p2+d).bonus != None and not cerca_reina(p2+d, id_reina)){
                      comida_trobat = true;
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2;
                      comida_dir = encontrar_direccion(P, p, p2+d);
                  }
                  else {
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2;
                      q.push(p2+d);
                  }
              }
          }
      }
      return {comida_dir, comida_trobat};
  }

bool pos_valida_reina(Pos p, int id) {
  if (cell(p).id == -1) return true;
  else {
    Ant a = ant(cell(p).id);
    if (a.id == id) return true;
  }
  return false;
}

bool pos_valida_hormiga(Pos p) {
  if (cell(p).id == -1) return true;
  else {
    Ant a = ant(cell(p).id);
    if (a.player != me()) return true;
  }
  return false;
}
bool cerca_reina(Pos p, int id_reina){
  vector<Pos> pos_q = {{-1,0}, {-2,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}, {0,1}, {0,2}, {1,0}, {2,0}, {0,-1}, {0,-2}};
  int n = pos_q.size();
  for (int i = 0; i < n; ++i){
    if (pos_ok(pos_q[i]+p) and cell(pos_q[i]+p).type != Water and cell(pos_q[i]+p).id == id_reina) return true;
  }
  return false;
}

Direccion buscar_reina(Pos p, int id_reina){
      //declaro medidas tablero
      int N = board_rows();
      int M = board_cols();
      //declaro tablero de pasos
      Pasos P(N, vector<Posicion>(M, {{-1,-1},false}));
      bool reina_trobat = false;
      queue<Pos> q;
      //direccion donde esta la reina
      Dir reina_dir = Up;
      q.push(p);
      P[p.i][p.j].second = true;
      while (not reina_trobat and not q.empty()){
          Pos p2 = q.front();
          q.pop();
          for (Dir d : dirs){
              if(pos_ok(p2+d) and not reina_trobat and pos_valida_reina(p2+d, id_reina) and 
              cell(p2+d).type != Water and not P[(p2+d).i][(p2+d).j].second
              and not pos_marcada(p2+d)){
                  if(cell(p2+d).id == id_reina){
                      reina_trobat = true;
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2;
                      reina_dir = encontrar_direccion(P, p, p2+d);
                  }
                  else {
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2;
                      q.push(p2+d);
                  }
              }
          }
      }
      return {reina_dir, reina_trobat};
  }

  Direccion buscar_enemigo(Pos p){
      //declaro medidas tablero
      int N = board_rows();
      int M = board_cols();
      //declaro tablero de pasos
      Pasos P(N, vector<Posicion>(M, {{-1,-1},false}));
      bool enemic_trobat = false;
      queue<Pos> q;
      //direccion donde esta el enemigo
      Dir enemic_dir = Up;
      q.push(p);
      P[p.i][p.j].second = true;
      while (not enemic_trobat and not q.empty()){
          Pos p2 = q.front();
          q.pop();
          for (Dir d : dirs){
              if(not enemic_trobat and pos_ok(p2+d) and cell(p2+d).type != Water 
              and not P[(p2+d).i][(p2+d).j].second and not pos_marcada(p2+d)){
                  Ant a;
                  if (cell(p2+d).id != -1) a = ant(cell(p2+d).id);
                 
                  if(cell(p2+d).id != -1 and a.player != me() and a.type == Worker){
                      enemic_trobat = true;
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2;
                      enemic_dir = encontrar_direccion(P, p, p2+d);
                  }
                  else {
                      P[(p2+d).i][(p2+d).j].second = true;
                      P[(p2+d).i][(p2+d).j].first = p2; 
                      q.push(p2+d);
                  }
              }
          }
      }
      return {enemic_dir, enemic_trobat};
  }

  Dir pos_vacia(const vector<Dir>& dirs, Pos p){
    int n = dirs.size();
    for (int i = 0; i < n; ++i){
      if (pos_ok(p+dirs[i]) and cell(p+dirs[i]).id == -1) return dirs[i];
    }
    return Up;
  }

  bool puedo_huevo_soldier(const Ant& a) {
    if (a.reserve[0] >= soldier_carbo() and a.reserve[1] >= soldier_prote() and a.reserve[2] >= soldier_lipid())
      return true;
    return false;
  }

  bool puedo_huevo_worker(const Ant& a) {
    if (a.reserve[0] >= worker_carbo() and a.reserve[1] >= worker_prote() and a.reserve[2] >= worker_lipid())
      return true;
    return false;
  }

  int max_alimento(int pa, int h, int pi){
    if(pa > h and pa > pi) return 1;
    else if(h > pa and h > pi) return 2;
    else if(pi > pa and pi > h) return 3;
    else{
      int ra = random(1,3);
      return ra;
    }
  }

//funcion para cojer alimento
  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    //identificacion trabajadores
    vector<int> w = workers(me());
    //identificacion soldados
    vector<int> s = soldiers(me());
    //identificacion reinas
    vector<int> q = queens(me());

    marcadas.clear();
    
    //obreras
    for (int id : w){
      Pos p1 = ant(id).pos;
      if (cell(p1).bonus != None and ant(id).bonus == None and not cerca_reina(p1, q[0])) {
        take(id);
        anadir_marca(p1);
      }
      else if (ant(id).bonus != None) {
        if (cerca_reina(p1, q[0]) and cell(p1).bonus == None) {
          leave(id);
          anadir_marca(p1);
        }
        else {
          Direccion d = buscar_reina(p1, q[0]);
          if (d.second){
            move(id, d.first);
            anadir_marca(p1+d.first);
          }
        }
      }
      else {
        bool comida_trobat = false;
        for (Dir d : dirs){
          if(pos_ok(p1+d) and cell(p1+d).id == -1 and 
              cell(p1+d).type != Water and not pos_marcada(p1+d) and cell(p1+d).bonus != None
              and not cerca_reina(p1+d, q[0])){
                comida_trobat = true;
                move(id, d);
                anadir_marca(p1+d);
          }
       }
        if (not comida_trobat) {
          Direccion d;
          if (nutrients[0] < nutrients[1] and nutrients[0] < nutrients[2]){
          //necesito carbohidratos
            int alimento = max_alimento(bread_carbo(), leaf_carbo(), seed_carbo());
            if (alimento == 1){
              //busco pan
              d = buscar_pan(p1, q[0]);
              if (d.second){
                move(id, d.first);
                anadir_marca(p1+d.first);
              }
            }
            if (not d.second or alimento == 2){
              //busco hoja
              d = buscar_hoja(p1, q[0]);
              if (d.second){
                move(id, d.first);
                anadir_marca(p1+d.first);
              }
            }
            if (not d.second or alimento == 3) {
              //busco pipa
              d = buscar_pipa(p1, q[0]);
              if (d.second){
                move(id, d.first);
                anadir_marca(p1+d.first);
              }
            }
          }
          else if (nutrients[1] < nutrients[0] and nutrients[1] < nutrients[2]){
            //necesito proteinas
            int alimento = max_alimento(bread_prote(), leaf_prote(), seed_prote());
            if (alimento == 1){
              //busco pan
              d = buscar_pan(p1, q[0]);
              if (d.second){
                move(id, d.first);
                anadir_marca(p1+d.first);
              }
            }
            if (not d.second or alimento == 2){
              //busco hoja
              d = buscar_hoja(p1, q[0]);
              if (d.second){
                move(id, d.first);
                anadir_marca(p1+d.first);
              }
            }
            if (not d.second or alimento == 3) {
              //busco pipa
              Direccion d = buscar_pipa(p1, q[0]);
              if (d.second){
                move(id, d.first);
                anadir_marca(p1+d.first);
              }
            }
          }
          else if (nutrients[2] < nutrients[0] and nutrients[2] < nutrients[1]) {
            //necesito lipidos
            int alimento = max_alimento(bread_lipid(), leaf_lipid(), seed_lipid());
            if (alimento == 1){
              //busco pan
              d = buscar_pan(p1, q[0]);
              if (d.second){
                move(id, d.first);
                anadir_marca(p1+d.first);
              }
            }
            if (not d.second or alimento == 2){
              //busco hoja
              d = buscar_hoja(p1, q[0]);
              if (d.second){
                move(id, d.first);
                anadir_marca(p1+d.first);
              }
            }
            if (not d.second or alimento == 3) {
              //busco pipa
              d = buscar_pipa(p1, q[0]);
              if (d.second){
                move(id, d.first);
                anadir_marca(p1+d.first);
              }
            }
          }
          else {
            Direccion d = buscar_comida(p1, q[0]);
            if (d.second){
              move(id, d.first);
              anadir_marca(p1+d.first);
            }
          }
        }
      }
    }
    //solados
    for (int id1 : s){
      Pos p2 = ant(id1).pos;
      Direccion d = buscar_enemigo(p2);
      if (pos_valida_hormiga(p2+d.first)){
        if (d.second ){
          move(id1, d.first);
          anadir_marca(p2+d.first);
        }
      }
      
    }  
    //reina
    for(int id2 : q){
        Pos p3 = ant(id2).pos;
        if (round()%queen_period() == 0){
          vector<Pos> pos_q = {{-1,0}, {0,1}, {1,0}, {0,-1}};
          int n = pos_q.size();
          bool mueve = false;
          //primero dist 1
          for (int i = 0; i < n and not mueve; ++i){
            Pos x = p3 + pos_q[i];
            if (pos_ok(x) and cell(x).id == -1 and cell(x).bonus != None and not pos_marcada(x)
              and cell(x).type != Water){
              if (i == 0) move(id2, Up);
              else if (i == 1) move(id2, Right);
              else if (i == 2) move(id2, Down);
              else move(id2, Left);
              mueve = true;;
            }
            else if (pos_ok(x) and cell(x).id != -1 and ant(cell(x).id).player != me() and cell(x).type != Water){
              if (i == 0) move(id2, Up);
              else if (i == 1) move(id2, Right);
              else if (i == 2) move(id2, Down);
              else move(id2, Left);
              mueve = true;;
            }
          }
          //dist 2
          for (int i = 0; i < n and not mueve; ++i){
            Pos x = p3 + pos_q[i];
            if (pos_ok(x) and cell(x).id == -1 and not pos_marcada(x) and cell(x).type != Water){
              for (int j = 0; j < n and not mueve; ++j) {
                Pos y = x + pos_q[j];
                if (pos_ok(y) and cell(y).id == -1 and cell(y).bonus != None and not pos_marcada(y)){
                  if (i == 0) move(id2, Up);
                  else if (i == 1) move(id2, Right);
                  else if (i == 2) move(id2, Down);
                  else move(id2, Left);
                  mueve = true;
                }
              }
            }
          }
          if (not mueve or (w.size() == 0)) {
            Direccion d = buscar_comida(p3, id2);
            if (d.second){
              move(id2, d.first);
            }
          }
        }
        if (puedo_huevo_soldier(ant(id2))){
          Dir d = pos_vacia(dirs, p3);
          if (pos_ok(p3+d) and cell(p3+d).type != Water)
          lay(id2,d,Soldier);
        }
        else if (puedo_huevo_worker(ant(id2)) and int(s.size()) >= 1){
          //and int(s.size()) >= 1
          Dir d = pos_vacia(dirs, p3);
          if (pos_ok(p3+d) and cell(p3+d).type != Water)
          lay(id2,d,Worker);
        } 
    }  
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
