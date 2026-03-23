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
