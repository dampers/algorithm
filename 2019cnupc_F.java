import java.math.*;
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws Exception{
		Scanner s=new Scanner(System.in);
		String st=s.next();
		int cntl=0;
		int cntr=0;
		int t=0;
		for(int i=0;i<st.length();i++) {
			if(st.charAt(i)==')') {
				
				t=i;
				break;
			}
		}
		for(int i=0;i<t;i++) {
			if(st.charAt(i)=='@') {
				cntl++;
			}
		}
		for(int i=t;i<st.length();i++) {
			if(st.charAt(i)=='@') {
				cntr++;
			}
		}
		System.out.println(cntl+" "+cntr);
	}

}