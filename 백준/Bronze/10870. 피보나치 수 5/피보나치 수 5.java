import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class Main
{   
    public static void main(String[] args) throws IOException
    {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(bf.readLine());
        
        if(n == 0 || n == 1)
        {
            bw.write(n+"\n");
            bw.flush();
            bw.close();
            return;
        }
        
        int a = 0, b = 1, c=0;
        for(int i=2; i<=n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        bw.write(c+"\n");
        bw.flush();
        bw.close();
    }
}