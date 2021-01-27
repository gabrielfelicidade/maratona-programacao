import java.util.*

fun main(args: Array<String>) {
    val sc = Scanner(System.`in`);

    val x = sc.nextInt()

    println(if(x%2 == 0 && x != 2) "YES" else "NO")
}