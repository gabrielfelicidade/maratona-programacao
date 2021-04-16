import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());

        br.readLine();

        while(t > 0) {
            String line;
            int total = 0;
            HashMap<String, Integer> map = new HashMap<String, Integer>();
            while((line = br.readLine()) != null && !line.isEmpty()) {
                total++;
                if (map.containsKey(line)) {
                    map.replace(line, map.get(line) + 1);
                } else {
                    map.put(line, 1);
                }
            }
            t--;
            Set<String> keys = new TreeSet<>();
            map.keySet().stream().forEach(it -> keys.add(it));
            for(String k: keys) {
                bw.write(k + " " + (new DecimalFormat("##0.0000").format(100.0*map.get(k)/total)) + "\n");
            }
            if (t > 0) {
                bw.write("\n");
            }
        }

        br.close();
        bw.close();
    }

}