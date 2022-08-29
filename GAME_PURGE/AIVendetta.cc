#include "Player.hh"
#include "Settings.hh"
#include "Structs.hh"
#include "State.hh"
#include <vector>
#include <queue>



/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Vendetta 

// DISCLAIMER: The following Demo player is *not* meant to do anything
// sensible. It is provided just to illustrate how to use the API.
// Please use AINull.cc as a template for your player.

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
  const vector<Dir> dirs = {Up,Down,Left,Right};
  typedef pair<Pos, bool> Posicion;
  typedef pair<Dir, bool> Direccion;
  typedef vector<vector<Posicion>> Pasos;
  
Dir encontrar_direccio (Pasos& P, Pos ini, Pos fin) {
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
	else return encontrar_direccio(P, ini, P[fin.i][fin.j].first);
}

Direccion busqueda_bazooka(Pos p){
	// declaracion del tablero
	int N = board_rows();
	int M = board_cols();
	Pasos P (N, vector<Posicion>(M, {{-1,-1}, false}));
	bool bazooka_trobat = false;
	queue<Pos> q;
	// direccion donde se encuentra el bazooka
	Dir bazooka_dir = Up;
	//añado posicion a la cola
	q.push(p);
	P[p.i][p.j].second = true;
	//mientras que no encuentre de bazooka y la cola no este vacia
	while (not bazooka_trobat and not q.empty()){
		//miro la posicion
		Pos p2 = q.front();
		q.pop(); 
		for (Dir d : dirs) {
			if (not bazooka_trobat and pos_ok(p2+d) and cell(p2+d).id == -1 and cell(p2+d).type != Building and not P[(p2+d).i][(p2+d).j].second){
				if (cell(p2+d).weapon == Bazooka ) {
					bazooka_trobat = true;
					P[(p2+d).i][(p2+d).j].second = true;
					P[(p2+d).i][(p2+d).j].first = p2;
					bazooka_dir = encontrar_direccio(P, p, p2+d);
				}
				else  {
					P[(p2+d).i][(p2+d).j].second = true;
					P[(p2+d).i][(p2+d).j].first = p2;
					q.push(p2+d);
				}
			}
		}
	}
	//Direccion res(bazooka_dir,bazooka_trobat);
	return {bazooka_dir,bazooka_trobat};
}
Direccion busqueda_money(Pos p){
	// declaracion del tablero
	int N = board_rows();
	int M = board_cols();
	Pasos P (N, vector<Posicion>(M, {{-1,-1}, false}));
	bool money_trobat = false;
	queue<Pos> q;
	// direccion donde se encuentra el dinero
	Dir money_dir = Up;
	//añado posicion a la cola
	q.push(p);
	P[p.i][p.j].second = true;
	//mientras que no encuentre de dinero y la cola no este vacia
	while (not money_trobat and not q.empty()){
		//miro la posicion
		Pos p2 = q.front();
		q.pop(); 
		for (Dir d : dirs) {
			if (not money_trobat and pos_ok(p2+d) and cell(p2+d).id == -1 and cell(p2+d).type != Building and not P[(p2+d).i][(p2+d).j].second){
				if (cell(p2+d).bonus  == Money) {
					money_trobat = true;
					P[(p2+d).i][(p2+d).j].second = true;
					P[(p2+d).i][(p2+d).j].first = p2;
					money_dir = encontrar_direccio(P, p, p2+d);
				}
				else  {
					P[(p2+d).i][(p2+d).j].second = true;
					P[(p2+d).i][(p2+d).j].first = p2;
					q.push(p2+d);
				}
			}
		}
	}
	return {money_dir,money_trobat};
}
Direccion busqueda_barricada(Pos p){
	// declaracion del tablero
	int N = board_rows();
	int M = board_cols();
	Pasos P (N, vector<Posicion>(M, {{-1,-1}, false}));
	bool barricada_trobat = false;
	queue<Pos> q;
	// direccion donde se encuentra el dinero
	Dir barricada_dir = Up;
	//añado posicion a la cola
	q.push(p);
	P[p.i][p.j].second = true;
	//mientras que no encuentre de dinero y la cola no este vacia
	while (not barricada_trobat and not q.empty()){
		//miro la posicion
		Pos p2 = q.front();
		q.pop(); 
		for (Dir d : dirs) {
			if (not barricada_trobat and pos_ok(p2+d) and cell(p2+d).id == -1 and cell(p2+d).type != Building and not P[(p2+d).i][(p2+d).j].second){
				if (cell(p2+d).resistance != -1 and cell(p2+d).b_owner == me()) {
					barricada_trobat = true;
					P[(p2+d).i][(p2+d).j].second = true;
					P[(p2+d).i][(p2+d).j].first = p2;
					barricada_dir = encontrar_direccio(P, p, p2+d);
				}
				else  {
					P[(p2+d).i][(p2+d).j].second = true;
					P[(p2+d).i][(p2+d).j].first = p2;
					q.push(p2+d);
				}
			}
		}
	}
	return {barricada_dir, barricada_trobat};
}

Direccion busqueda_rival(Pos p){
	// declaracion del tablero
	int N = board_rows();
	int M = board_cols();
	Pasos P (N, vector<Posicion>(M, {{-1,-1}, false}));
	bool rival_trobat = false;
	queue<Pos> q;
    int id_equipo = me();
	// direccion donde se encuentra el rival
	Dir rival_dir = Up;
	//añado posicion a la cola
	q.push(p);
	P[p.i][p.j].second = true;
	//mientras que no encuentre rival y la cola no este vacia
	while (not rival_trobat and not q.empty()){
		//miro la posicion
		Pos p2 = q.front();
		q.pop(); 
		for (Dir d : dirs) {
            //and cell(p2+d).id == -1
			if (not rival_trobat and pos_ok(p2+d) and cell(p2+d).type != Building and not P[(p2+d).i][(p2+d).j].second and cell(p2+d).b_owner == -1){
				int id = cell(p2+d).id;
                if (id != -1 and citizen(id).player != id_equipo) {
					rival_trobat = true;
					P[(p2+d).i][(p2+d).j].second = true;
					P[(p2+d).i][(p2+d).j].first = p2;
					rival_dir = encontrar_direccio(P, p, p2+d);
				}
				else  {
					P[(p2+d).i][(p2+d).j].second = true;
					P[(p2+d).i][(p2+d).j].first = p2;
					q.push(p2+d);
				}
			}
		}
	}
	//Direccion res(bazooka_dir,bazooka_trobat);
	return {rival_dir,rival_trobat};
}
  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
	//identificacion de los guerreros
	vector<int> w = warriors(me());
	//identificacion de los constructores
	vector<int> b = builders(me());

	if (is_day()){
		for (int id : w){
			Pos p1 = citizen(id).pos;
			//miro posiciones cercanas
			bool mueve = false;
			for (Dir d : dirs){
				// si me encuentro dinero, si mi vida es inferior o igual a 80 restauro vida
				// y si encuentro por el camino una pistola teniendo martillo
				if (pos_ok(p1+d) and (cell(p1+d).bonus == Money or cell(p1+d).bonus == Food or
				cell(p1+d).weapon == Gun or cell(p1+d).weapon == Bazooka)){
					//me muevo a dicha pos y lo cojo
					move(id, d);
					mueve = true;
					break;
				}
			}
			if (not mueve) {
			// aunque lo tenga se lo quito a los contrincantes
				Direccion d = busqueda_bazooka(p1);
				//Direccion d1 = busqueda_money(p1);
				bool no_bazookas = false;

				if (d.second){
					move(id, d.first);
				}
				else {
					// o en vez de buscar dinero acercase a los rivales para asi en la noche acorralar. 
					// de cara a la noche mirar si no tengo bazooka y tienes rival que sea con bazooka huir.
					Direccion d1 = busqueda_money(p1);
					if (d1.second){
						move(id, d1.first);
					}
					//else moverse(agrupase soldados)
				}
			}
		}
		int ronda_act = round();
		int cont_barricada = barricades(me()).size();
		for (int ib: b){
			Pos p = citizen(ib).pos;
			bool mueve = false;
			for (Dir d: dirs){
				if (pos_ok(p+d)) {
					if ((cell(p+d).bonus == Money or cell(p+d).bonus == Food or
					cell(p+d).weapon == Gun or cell(p+d).weapon == Bazooka)) {
						move(ib, d);
						mueve = true;
						break;
					}
					else if (cell(p+d).resistance != -1 and cell(p+d).b_owner == me()) {
						if (cell(p+d).resistance < barricade_max_resistance()) {
							build(ib, d);
							mueve = true;
							break;
						}
					}
					//piensas que es necesario para la estrategia? siendo constructor miro
					// que mis compas guerreros tengan bazookas para no robarselos hasta que todos
					//tengan. (mirar el else!)
					/*for (int id : w){
						if (citizen(id).weapon == Bazooka){
							if((cell(p+d).weapon == Bazooka) or (cell(p+d).weapon == Gun)){
								move(ib, d);	
							}
							else {
								move(ib, d1.first);
							}
						}
					}*/
				}
			}
			if (not mueve) {
				//si la ronda 2 siguiente: construir barricada(1 ronda), posicionarse barricada (1 ronda)
				// se generan warnings problema solo puedo contruir 3 barricadas por ronda!!
			
				if (is_round_night(ronda_act+8)){
					Pos actual = citizen(ib).pos;
					for (Dir d: dirs){
						if (pos_ok(actual+d) and cell(actual+d).is_empty() and cont_barricada < max_num_barricades()){
							build(ib,d);
							++cont_barricada;
							mueve = true;
							break;
						}
					}
				}
				if (not mueve) {
					Direccion d1 = busqueda_money(p);
					if (d1.second){
						move(ib, d1.first);
					}
				}
			}
		}
	}
	//caso de noche 
	else {
		for (int id : w){
			Pos p1 = citizen(id).pos;
			bool mueve = false;
			//miro posiciones cercanas
			for (Dir d : dirs){
				// si me encuentro dinero, si mi vida es inferior o igual a 80 restauro vida
				// y si encuentro por el camino una pistola o bazooka
				if (pos_ok(p1+d)){
					if (cell(p1+d).id != -1 and citizen(cell(p1+d).id).player != me()) {
						move(id, d);
						mueve = true;
						break;
					}
					else if ((cell(p1+d).bonus == Money) or (citizen(id).life <= 80 and cell(p1+d).bonus == Food) or
					(cell(p1+d).weapon == Bazooka) or (cell(p1+d).weapon == Gun)){
						//me muevo a dicha pos y lo cojo
						move(id, d);
						mueve = true;
						break;
					}
				}
			}
			if(not mueve){
				// aunque lo tenga se lo quito a los contrincantes
				Direccion d = busqueda_rival(p1);
				if (d.second){
					move(id, d.first);
				}
			}
			
		}
		for (int ib : b){
			Pos p = citizen(ib).pos;
			if (cell(p).b_owner == -1) {
				bool mueve = false;
				for (Dir d : dirs){
					if (pos_ok(p+d)){
						//si enemigo cerca me muevo a la barricada 
						// si hay barricada aliada (deberia tener en cuenta proximidad del enemigo) 
						if (cell(p+d).resistance != -1 and cell(p+d).b_owner == me()) {
						
							//sino ocupada me meto (cuidado si dos a la vez)
							if (cell(p+d).id == -1){
								move(ib, d);
								mueve = true;
								break;
							}
						}
						//prefiero ir a por bonus i quitar al enemigo en vez de luchar entre constructores
						else if ((cell(p+d).bonus == Money) or (cell(p+d).bonus == Food) or
						(cell(p+d).weapon == Bazooka) or (cell(p+d).weapon == Gun)){
							//me muevo a dicha pos y lo cojo
							move(ib, d);
							mueve = true;
							break;
						}
					}
				}
				if (not mueve){
					//busco barricada aliada no ocupada, sino me muevo en busca de bonus
					Direccion d1 = busqueda_barricada(p);
					if (d1.second){
						move(ib, d1.first);
					}
					//sino bonus
					else {
						// o en vez de buscar dinero acercase a los rivales para asi en la noche acorralar. 
						// de cara a la noche mirar si no tengo bazooka y tienes rival que sea con bazooka huir.
						Direccion d1 = busqueda_money(p);
						if (d1.second){
							move(ib, d1.first);
						}
						//else moverse(agrupase soldados)
					}
				}
			}
			else {//estoy dentro de barricada
				Pos p = citizen(ib).pos;
				for (Dir d : dirs){
					if (pos_ok(p+d)){
						//si enemigo cerca me muevo a la barricada 
						// si hay barricada aliada (deberia tener en cuenta proximidad del enemigo) 
						if (cell(p+d).id != -1 and citizen(cell(p+d).id).player != me() and citizen(cell(p+d).id).type == Builder) {
							move(ib, d);
							break;
						}
					}
				}
			}
		}

	}
  }
};




/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
