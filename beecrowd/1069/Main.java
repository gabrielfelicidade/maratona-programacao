import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(br.readLine());

        while(n-- > 0) {
            String line = br.readLine();
            Stack<Character> stack = new Stack<>();
            int cont = 0;
            for(Character c : line.toCharArray()) {
                if (c == '<') {
                    stack.push(c);
                } else if (c == '>' && !stack.isEmpty()) {
                    cont++;
                    stack.pop();
                }
            }
            bw.write(cont + "\n");
        }

        br.close();
        bw.close();
    }

}