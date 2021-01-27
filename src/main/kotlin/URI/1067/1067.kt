import java.util.*

fun main(args: Array<String>) {
    val sc = Scanner(System.`in`);

    val x = sc.nextInt()

    (1..x).filter { it % 2 == 1 }.forEach { println(it) }
}