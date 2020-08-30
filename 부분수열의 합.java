import java.util.Scanner;

public class Main {
	static int cnt = 0;
	static void backtracking(int arr[], int cur, int sum, int S) {
		if (sum == S) {
			// System.out.println("Ã£À½!");
			cnt++;
		}
		for (int i = cur + 1; i < arr.length; ++i) {
			backtracking(arr,i,sum+arr[i],S);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int S = sc.nextInt();
		int a[] = new int[N];
		for (int i = 0; i < N; ++i) {
			a[i] = sc.nextInt();
		}
		for(int i=0;i<N;++i) {
			backtracking(a,i,a[i],S);
		}
		System.out.println(cnt);
		sc.close();
	}
	

}
