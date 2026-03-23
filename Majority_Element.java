import java.util.*;

public class Main
{
    public static int MajorCall(int[]nums){
    HashMap<Integer,Integer>map=new HashMap<>();
    int limit=nums.length/2;
    
    for(int num:nums){
        int count=map.getOrDefault(num,0)+1;
        map.put(num,count);
        if(count>limit){
            return num;
        }
    }
    return -1;
}
	public static void main(String[] args) {
	    Scanner sc=new Scanner(System.in);
	    System.out.println("enter n");
	    int n=sc.nextInt();
	    
	    int []nums=new int[n];
		
		System.out.println("enter elements");
		for(int i=0;i<n;i++){
		    nums[i]=sc.nextInt();
		}
		
		int result=MajorCall(nums);
		System.out.println("result is"+result);
	}
}
//power of 2
public static boolean isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}


//count set bits
int n = sc.nextInt();
System.out.println(Integer.bitCount(n));

//hamming dist
int x = sc.nextInt();
int y = sc.nextInt();
System.out.println(Integer.bitCount(x ^ y));

//trailing zeros in fact
    int count = 0;
    while (n > 0) {
        n /= 5;
        count += n;
    }
    return count;
}


//binary palindrome
public static boolean isBinaryPalindrome(int n) {
    String s = Integer.toBinaryString(n);
    int i = 0, j = s.length() - 1;

    while (i < j) {
        if (s.charAt(i) != s.charAt(j)) return false;
        i++;
        j--;
    }
    return true;
}
