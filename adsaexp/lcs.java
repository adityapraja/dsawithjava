import java.util.Scanner;

public class lcs 
{
    public static void main(String[] args)
    {
        Scanner sc= new Scanner(System.in);

        System.out.println("Enter the String 1:");
        String string1= sc.nextLine();

        System.out.println("Enter the String 2:");
        String string2= sc.nextLine();
        int n= string1.length();
        int m= string2.length();
        // System.out.println(n +" "+ m);
        int arr[][] =  new int[n+1][m+1];
        
        for(int i=0;i<n+1;i++){
            arr[i][0]=0;
        }

        for(int j=0;j<m+1;j++){
             arr[0][j]=0;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(string1.charAt(i-1)==string2.charAt(j-1)){
                    arr[i][j] = 1 + arr[i-1][j-1];
                }
                else{
                    arr[i][j]= Math.max(arr[i-1][j],arr[i][j-1]);
                }
        }

    }
  
    

    System.out.println("LCS: "+ arr[n][m]);
    String lcsString = "";
    int a=n,b=m;

    StringBuilder lcsstring = new StringBuilder();
    while (a > 0 && b > 0) {
        if (string1.charAt(a - 1) == string2.charAt(b - 1)) 
        {
            lcsstring.append(string1.charAt(a-1));
            a--;
            b--;
        } 
        else if (arr[a - 1][b] > arr[a][b - 1]) 
        {
            a--;
        } 
        else 
        {
            b--;
        }

    }
    System.out.println("LCS String: "+ lcsstring.reverse().toString());
    sc.close();
    }
}

