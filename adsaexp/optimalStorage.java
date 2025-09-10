import java.util.Scanner;

public class optimalStorage {
    public static void main(String[] args) {   
        Scanner sc = new Scanner(System.in);
        
        int n;
        int MRT=0;
        System.out.print("Enter the number of Memories:");
        n = sc.nextInt();
        int[] arr = new int[n];

        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        bubble(arr, n);

        
      

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<i;j++){
            sum=sum+arr[j];
            }
            MRT=MRT+sum;
        }
        System.out.println("MRT:"+MRT);

      
    }

    public static void bubble(int arr[], int n) {
        for(int i = 0; i < n-1; i++) {           
            for(int j = 0; j < n-1-i; j++) {
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp; 
                }
            }
        }
    }
}
