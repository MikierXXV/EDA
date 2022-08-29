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
	Dir bazooka_dir;
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
	// direccion donde se encuentra el bazooka
	Dir money_dir;
	//añado posicion a la cola
	q.push(p);
	P[p.i][p.j].second = true;
	//mientras que no encuentre de bazooka y la cola no este vacia
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
			for (Dir d : dirs){
				// si me encuentro dinero, si mi vida es inferior o igual a 80 restauro vida
				// y si encuentro por el camino una pistola teniendo martillo
				if ((cell(p1+d).bonus == Money) or (citizen(id).life <= 80 and cell(p1+d).bonus == Food) or
				(citizen(id).weapon != Bazooka and cell(p1+d).weapon == Gun)){
					//me muevo a dicha pos y lo cojo
					move(id, d);
				}
			}
			// aunque lo tenga se lo quito a los contrincantes
			Direccion d = busqueda_bazooka(p1);
			if (d.second){
				move(id, d.first);
			}
			
		}
		for (int ib: b){
			Pos p = citizen(ib).pos;
			for (Dir d: dirs){
				if (citizen(ib).life <= 40 and cell(p+d).bonus == Food){
					move(ib, d);
				}
			}
			Direccion d1 = busqueda_money(p);
			if (d1.second){
				move(ib, d1.first);
			}
		}
	}
  }
};














	/*
    // If nearly out of time, do nothing.
    double st = status(me());
    if (st >= 0.9) return;

    // If more than halfway through, do nothing.
    if (round() > num_rounds()/2) return;

    // Write debugging info about barricades
    vector<Pos> bs = barricades(me());
    cerr << "At round " << round() << " player " << me() << " has " << bs.size() << " barricades:" << endl;
    for (Pos& p : bs) {
      Cell c = cell(p);
      cerr << "Pos " << p << " with resistance " << c.resistance << endl;
    }

    
    if (is_day()) {
      
      // At day take care of builders
      vector<int> b = builders(me());
      for (int id : b) { // Iterate over all builders
	Pos p = citizen(id).pos;


	
	// If there is food nearby, move there
	bool food_nearby = false;
	Dir food_dir;
	for (Dir d : dirs) {
	  if (pos_ok(p+d) and cell(p+d).bonus == Food) {
	    food_nearby = true;
	    food_dir = d;
	  }
	}
	if (food_nearby) move(id,food_dir);	
	else { // No food nearby
	  if (random(0,3) <= 1) {// Do this with 25% probability [try to build in random position]
	    bool some_dir = false;
	    for (uint i = 0; not some_dir and i < dirs.size(); ++i){
	      Dir d = dirs[i];
	      Pos np = p + d;
	      if (pos_ok(np)) { // pos_ok checks np is in the board, but here something else would be needed to make   
		build(id,d);    // sure we can construct
		cerr << "build " << id << " dir " << d << endl;
		some_dir = true;
	      }
	    }
	  }
	  else { // Do this with 75% probability [move to money if possible, otherwise randomly]
	    Dir random_dir = dirs[random(0,3)];
	    if (pos_ok(p+random_dir) and (cell(p+random_dir).id == -1 or 
					  citizen(cell(p+random_dir).id).type == Builder)) { // Move there if no citizen or builder	     
	      move(id,random_dir);
	      cerr << "move " << id << " dir " << random_dir << endl;
	    }
	  }
	}
      }
    }
    else {
      // At night take care of warriors
      vector<int> w = warriors(me());
      for (int id : w) { // Iterate over all warriors
	if (random(0,9) < 6) {// 60 % probability move randomly, otherwise do nothing
	  Dir random_dir = dirs[random(0,3)];
	  Pos p = citizen(id).pos;
	  if (pos_ok(p+random_dir)) {
	    cerr << "move " << id << " dir " << random_dir << endl;
	    move(id,random_dir);
	  }
	}	
      }
    }
  }
};
*/


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
