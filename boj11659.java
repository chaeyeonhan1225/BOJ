package boj11659;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class boj11659 {

	public static void main(String[] args) {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		try {
			StringTokenizer st = new StringTokenizer(bf.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			st = null;
			st = new StringTokenizer(bf.readLine());
			int arr[] = new int[N+1];
			int s[] = new int[N+1];
			for(int i=0;i<N;++i) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			s[0] = 0;
			for(int i=1;i<=N;++i) {
				s[i] = s[i-1] + arr[i-1];
			}
			for(int i=0;i<M;++i) {
				StringTokenizer st1 = new StringTokenizer(bf.readLine());
				int a = Integer.parseInt(st1.nextToken());
				int b = Integer.parseInt(st1.nextToken());
				String ans = Integer.toString(s[b] - s[a-1]);
				bw.write(ans);
				bw.newLine();
			}
			bw.flush();
			bw.close();
		} catch(Exception e) {
			
		}
	}

}
