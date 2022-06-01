import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n1 = Integer.parseInt(br.readLine());
        int media = Integer.parseInt(br.readLine());

        bw.write((media*2-n1) + "\n");

        br.close();
        bw.close();
    }

}