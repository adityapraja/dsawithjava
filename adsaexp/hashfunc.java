import java.util.Scanner;

public class hashfunc
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the string:");
        String str= scanner.nextLine();
        int n= str.length();
        int s =0;
        for(int i=0;i<n;i++)
        {
            s=s+ascii(str.charAt(i));           //sums the ascii values of string
        }
        hashfunction(s,str);
    }

    public static char ascii(char a)
    {
        int asciiVal=a;         //typecasts the string to int for ascii values
        return a;
    }

    public static void hashfunction(int s,String str)
    {
        Scanner scanner= new Scanner(System.in);
        System.out.print("Enter the Size of Hash:");
        int n= scanner.nextInt();
        int j=s%n;              //calculates the index of hash
        String[] hash = new String[n];
        hash[j]=str;        //assigns the string to that index
        for(int i=0;i<10;i++)
        {
            System.out.println(i + ":"+ hash[i]);       //display of hash
        }

    }

}