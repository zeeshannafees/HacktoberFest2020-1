import java.util.*;
class digitPrimeChecker{
    public static void main(String[] args){
        int number, count=0, k=0;
        Scanner sc = new Scanner(System.in);
        number=sc.nextInt();
        while (number>0){
            count++;
            number/=10;
        }
        for(int i=1; i<=count; i++){
            if(count%i==0)
            k++;
            if(k>2 || count==2)
            break;
        }
        if(count==2 || k==2){
            System.out.println("Number Of Digits is Prime");
        }
        else{
            System.out.println("Number Of Digits is Not Prime");
        }
    }
}