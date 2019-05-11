import java.math.*;
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws Exception{
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		int[] power=new int[t];
		int max=0;
		int cnt=0;
		int cntR=0;
		int cntB=0;
		int juso=0;
		int juso2=0;
		for(int i=0;i<t;i++) {
			power[i]=s.nextInt();
			max=Math.max(max, power[i]);
		}
		for(int i=0;i<t;i++) {
			if(power[i]==max) {
				cnt++;
				juso=i;
			}
		}
		
		if(cnt==1) {
			cntR=juso;
			cntB=t-juso-1;
			if(cntR<cntB) {
				System.out.println("R");
			}
			else if(cntR==cntB) {
				System.out.println("X");
			}
			else if(cntR>cntB) {
				System.out.println("B");
			}
		}
		else {
			for(int i=0;i<juso;i++) {
				if(power[i]==max) {
					juso2=i;
					break;
				}
			}
			cntR=juso2;
			cntB=t-juso-1;
			if(cntR<cntB) {
				System.out.println("R");
			}
			else if(cntR==cntB) {
				System.out.println("X");
			}
			else if(cntR>cntB) {
				System.out.println("B");
			}
		}
	}

}
