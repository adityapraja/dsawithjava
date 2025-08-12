import java.util.Scanner;

public class MergeSortCode
{
    static int[] b; //Initialized Array b globally so that every class can access it.
    public static void main(String[] args)
    {   
        Scanner scanner = new Scanner(System.in);
        int[] a;
        
        System.out.println("Enter the number of elements in an Array:");
        int n = scanner.nextInt();     //inputs the size of arrays
        
        a = new int[n];                //initializations of arrays
        b = new int[n];

        System.out.println("Enter the Array to be sorted:");
        for(int i=0;i<n;i++)
        {
            a[i]=scanner.nextInt();                 //inputs the array that need to be sorted
        }

        mergesort(a,0,n-1);             //calls the mergesortfunction

        System.out.println("Sorted Array is:");
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i]+" ");         //prints the sorted array
        }
    }

    public static void mergesort(int[] a,int lb,int ub)
    {
        if(lb<ub)
        {
            int mid=(lb+ub)/2;          //recursively divides the array into sub arrays
            mergesort(a,lb,mid);
            mergesort(a,mid+1,ub);
            merge(a,lb,mid,ub);
        }
    }  

    public static void merge(int[] a,int lb,int mid,int ub)
    {
        int i=lb;
        int j=mid+1;
        int k=lb;
        while(i<=mid && j<=ub)
        {
            if(a[i]<=a[j])
            {
                b[k]=a[i];              //assigns the value to the new temp array from subarrays
                i++;
                k++;
            }
            else
            {
                b[k]=a[j];
                j++;
                k++;
            }
        }
    
        if(i>mid)                   //boundary condition
        {
            while(j<=ub)
            {
                b[k]=a[j];
                j++;
                k++;
            }
        }
        else
        {
            while(i<=mid)
            {
                b[k]=a[i];
                i++;
                k++;
            }
        }
        for(k=lb;k<=ub;k++)         //to assign any remaing elements after boundary conditions
        {
            a[k]=b[k];
        }
    }
}



