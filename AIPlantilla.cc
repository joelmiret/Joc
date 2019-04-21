#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Null


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

	using VI = vector<int>;
	using VVI = vector<VI>;
	using VP = vector<Pos>;
	using VVP = vector<VP>;
	VVP all_cities;

	void initialize_cities() {
        VVI used(60, VI(60, false));
        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 60; j++) {
                if (not used[i][j]) {
                    used[i][j] = true;
                    if (cell(i, j).type == City) {
                        vector<Pos> v;
                        queue<Pos> q;
                        q.push(Pos(i, j));
                        used[i][j] = true;
                        while (not q.empty()) {
                            Pos p = q.front();
                            q.pop();
                            if (cell(p).type == City) {
                                v.push_back(p);
                                for (int i = 0; i < 8; i++) {
                                    Dir d = Dir(i);
                                    Pos p2 = p+d;
                                    if (pos_ok(p2) and not used[p2.i][p2.j]) {
                                        q.push(p2);
                                        used[p2.i][p2.j] = true;
                                    }
                                }
                            }
                        }
                        all_cities.push_back(v);
                    }
                }
            }
        }
    }

  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
	  
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
