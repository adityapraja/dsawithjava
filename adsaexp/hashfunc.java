import java.util.Scanner;

public class hashfunc{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str= sc.nextLine();
        int n= str.length();
        int s =0;
        for(int i=0;i<n;i++){
            s=s+ascii(str.charAt(i));
        }
        hashfunction(s,str);
    }

    public static char ascii(char a){
        int asciiVal=a;
        return a;
    }

    public static void hashfunction(int s,String str){
        
        int j=s%10;
        String[] hash = new String[10];
        hash[j]=str;
        for(int i=0;i<10;i++){
            System.out.println(i + ":"+ hash[i]);
        }

    }

}