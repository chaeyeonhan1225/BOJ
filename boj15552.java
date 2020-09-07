package boj15552;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj15552 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		try {
			int t = Integer.parseInt(br.readLine());
			while (t-- > 0) {
				String s = br.readLine();
				String st[] = s.split(" ");
				int a = Integer.parseInt(st[0]);
				int b = Integer.parseInt(st[1]);
				String ans = Integer.toString(a+b);
				bw.write(ans);
				bw.newLine();
			}
			bw.flush();
			bw.close();
		} catch (Exception e) {

		}
	}

}
