package cfpg;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.TreeSet;

public class Main10422 {
	static final int MAX = 5;

	static final char FINAL_STATE_M[][] = new char[][]{
		"11111".toCharArray(),
		"01111".toCharArray(),
		"00 11".toCharArray(),
		"00001".toCharArray(),
		"00000".toCharArray(),
	};
	static final State FINAL_STATE = new State(FINAL_STATE_M);
	
	private static class State implements Comparable<State>{
		char m[][] = new char[MAX][MAX];

		public State(char [][] m ) {
			this.m = m;
		}
		@Override
		public int compareTo(State o) {
			
			for( int i = 0; i < MAX; ++ i )
				for( int j = 0; j < MAX ;++ j )
					if( m[i][j] != o.m[i][j] )
						return m[i][j] < o.m[i][j] ? -1 : 1;
			return 0;
		}
		@Override
		public String toString() {
			String ans = "";
			
			for(char[] a: m ) 
				ans += String.valueOf(a)+"\n";
			
			return ans.trim();
		}
		public ArrayList<State> getNeighbours() {
			ArrayList<State> ans = new ArrayList<State>();
			
			int blankRow = -1;
			int blankCol = -1;
			boolean found = false;
			for( int i = 0; i < MAX && !found; ++ i )
				for( int j = 0; j < MAX && !found; ++j )
					if( m[i][j] == ' ') {
						blankRow = i;
						blankCol = j;
						found = true;
					}
			
			for( int i = 0; i < dr.length; ++i ) { 
				int nr = dr[i] + blankRow;
				int nc = dc[i] + blankCol;
				if(!isIn(nr,nc))continue;
								
				char [][] mcopy = getCopy();
				
				char color = m[nr][nc];
				mcopy[blankRow][blankCol] = color;
				mcopy[nr][nc] = ' ';
				
				State newState = new State(mcopy);
				ans.add(newState);
			}
			
			return ans;
		}
		
		char[][] getCopy(){ 
			
			char [][] copy = new char[MAX][MAX];
			for( int i = 0; i < MAX; ++ i )
				for( int j = 0; j < MAX ;++ j )
					copy[i][j] = m[i][j];
			return copy;
		}
		
	}
	
	static boolean isIn(int r, int c) {
		return r >= 0 && r < MAX && c >= 0 && c < MAX;
	}
	
	static final boolean DEBUG = false;

	static int dr[] = new int [] {-2,-2,-1,-1,1,1,2,2};
	static int dc[] = new int [] {-1,1,-2,2,-2,2,-1,1};


	static int solve(State initialState) {
		//System.out.println(initialState);

		TreeSet<State> visited = new TreeSet<State>();
		Queue<State> q = new LinkedList<State>();
		Queue<Integer> distQ = new LinkedList<Integer>();
		
		q.add(initialState);
		distQ.add(0);
		visited.add(initialState);

		while(!q.isEmpty()) {
			
			State headNode = q.poll();
			int distToHead = distQ.poll();
			
			if( headNode.compareTo(FINAL_STATE) == 0 )
				return distToHead;
			
			if( distToHead >= 10 )
				continue;
			
			ArrayList<State> neighbours = headNode.getNeighbours();
			for( State neighbour : neighbours ) {
				if( !visited.contains(neighbour)) { 
					visited.add(neighbour);
					q.add(neighbour);
					distQ.add(distToHead + 1);
				}
			}
			
		}
		
		return -1;
	}

	public static void main(String args[]) {
		Scanner sn = new Scanner(System.in);

		int n = Integer.parseInt(sn.nextLine());
		
		for( int testCase = 0 ; testCase < n; ++ testCase ) {
			char [][] initialState = new char[MAX][MAX];
			for( int i = 0; i < MAX; ++ i ) 
				initialState[i] = sn.nextLine().toCharArray();
			
			int dist = solve( new State(initialState));
			if( dist < 0 )
				System.out.println("Unsolvable in less than 11 move(s).");
			else
				System.out.println("Solvable in "+dist+" move(s).");
			
		}
		
		sn.close();
	}
}
