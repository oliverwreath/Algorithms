/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package algoPkg;
import java.io.*;

/**
 *
 * @author HunterX
 */
public class AlgoPkg {

    /**
     * @param args the command line arguments
     */
    
    public static int[] swap(int a, int b){
        a = a^b;
        b = a^b;
        a = a^b;
        return (new int[] {a, b});
    }
    
    public static int addition( int a, int b ){
        if( b == 0 ){
            return a;
        }
        int sum = a^b;
        int carry = (a&b)<<1;
        return addition(sum, carry);
    }
    
    public static void main(String[] args) throws IOException{
        // TODO code application logic here
        BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
        int a = 345678;
        int b = 7654321;
        int [] ret = {0,0};
        for(int i = 1; i <= 9 ; i++){
            for(int j = 1; j <= 99 ; j++){
                ret = swap(a, b);
            }
        }
        System.out.println(ret[0]+" "+ret[1]);
        int ret2 = addition(a, b);
        System.out.println(ret2);
        return ;
    }
}
