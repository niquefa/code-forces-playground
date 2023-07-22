#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    
  int test_cases;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    int total_cards, total_jokers, players;
    cin >> total_cards >> total_jokers >> players;
    
    int cards_per_player = total_cards / players;
    int most_joker_for_player = total_jokers;
    
    if( cards_per_player < total_jokers ) {
      most_joker_for_player = cards_per_player;
    }

    int joker_left = total_jokers - most_joker_for_player;

    if( joker_left == 0 ) {
      cout << most_joker_for_player << endl;
      continue;
    }
    int second_most_joker_for_player = joker_left / (players - 1) + (joker_left % (players - 1) != 0);
    cout << most_joker_for_player - second_most_joker_for_player << endl;    
  }
  return 0;
}
