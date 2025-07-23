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

        System.out.println(s);
    }

    public static char ascii(char a){
        int asciiVal=a;
        return a;
    }

}