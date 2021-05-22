import java.io.IOException;
import java.util.Stack;
import java.util.Scanner;

public class StackandQueues {
	public static void DaoChu(String sms) {
		String temp = "";
		Stack<Character> st = new Stack<>();
		for (int i = 0; i < sms.length(); i++) {
			st.push(sms.charAt(i));
		}
		while (!st.empty()) {
			System.out.print(st.pop());
		}
	}

	public static void InttoBinary(String sms) {
		int so = Integer.parseInt(sms);
		String re = Integer.toBinaryString(so);
		System.out.println(re);
	}

	public static void MaHoa(String sms) {
		String re = "";
		Stack<Character> mahoa = new Stack<Character>();
		for (int i = 0; i < sms.length(); i++) {
//			System.out.println(sms.charAt(i));
			if(!mahoa.empty()) {
//				System.out.println("top " + mahoa.lastElement());
			}
			if (mahoa.empty() || sms.charAt(i) == mahoa.lastElement()) {
//				System.out.println("opush" + sms.charAt(i));
				mahoa.push(sms.charAt(i));
			} else {
				int count = 0;
				re += mahoa.lastElement();
				while (!mahoa.empty()) {
					count++;
					mahoa.pop();
				}
				re += Integer.toString(count);
				mahoa.push(sms.charAt(i));
			}
		}
		int count = 0;
		re += mahoa.lastElement();
		while (!mahoa.empty()) {
			count++;
			mahoa.pop();
		}
		re += Integer.toString(count);
		System.out.println(re);
	}

	public static void main(String[] args) {
		Scanner sn = new Scanner(System.in);
		String sms = sn.nextLine();
		MaHoa(sms);
	}
}
