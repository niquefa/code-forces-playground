package cfpg;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main567 {

	private static final boolean DEBUG = false;
	static final int MAX = 21;
	static ArrayList<Integer> adjList[] = new ArrayList[MAX];
	static boolean visited[] = new boolean[MAX];
	static int distTo[] = new int[MAX];


	static void init() {
		for (int i = 0; i < MAX; ++i)
			adjList[i] = new ArrayList<Integer>();
	}

	static void printGraph() {
		for (int node = 1; node <= 20; ++node) {
			System.out.print("Node " + node + " ("+adjList[node].size()+")-> ");
			for (int i = 0; i < adjList[node].size(); ++i)
				System.out.print(adjList[node].get(i) + " ");
			System.out.println();
		}
	}

	static int getBFSDistance(int from, int to) {
		Arrays.fill(visited, false);
		Arrays.fill(distTo, -1);
		
		visited[from] = true;
		Queue<Integer> q = new LinkedList<Integer>();
		Queue<Integer> distQ = new LinkedList<Integer>();

		q.add(from);
		distQ.add(0);
		while(!q.isEmpty()) {
			int headNode = q.poll();
			int distToHead = distQ.poll();
			if( headNode == to )
				return distToHead;
			for( int neighbour : adjList[headNode] ) {
				if( !visited[neighbour]) { 
					visited[neighbour] = true;
					q.add(neighbour);
					distQ.add(distToHead + 1);
				}
			}
			
		}
		return -1;
	}

	public static void main(String args[]) {
		Scanner sn = new Scanner(System.in);
		int testCaseCounter = 1;
		while (true) {
			if( !sn.hasNextLine() )
				break;
			init();
			for (int node = 1; node <= 19; ++node) {
				String line = sn.nextLine();
				if (line == null || line.trim().length() == 0)
					System.exit(0);

				

				String arr[] = line.split(" ");
				int X = Integer.parseInt(arr[0]);
				for (int j = 1; j <= X; ++j) {
					int neighbour = Integer.parseInt(arr[j]);
					adjList[node].add(neighbour);
					adjList[neighbour].add(node);
				}
			}

			int N = Integer.parseInt(sn.nextLine());

			if (DEBUG) {
				System.out.println("Test Case: " + testCaseCounter);
				printGraph();
			}
			
			System.out.println("Test Set #" + testCaseCounter);


			for (int i = 0; i < N; ++i) {
				String arr[] = sn.nextLine().split(" ");
				int A = Integer.parseInt(arr[0]);
				int B = Integer.parseInt(arr[1]);
				int distance = getBFSDistance(A, B);
				System.out.println(norm(A) + " to " + norm(B) + ":" + norm(distance));
			}

			testCaseCounter++;

			System.out.println();
		}
	}

	private static String norm(int x) {
		return x > 9 ? x + "" : " " + x;
	}
}
