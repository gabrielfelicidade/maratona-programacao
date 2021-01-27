import java.util.*

fun main(args: Array<String>) {
    val sc = Scanner(System.`in`);

    val a = sc.nextInt()
    val n = sc.nextInt()

    val amount = (0 until n).map { sc.nextInt() }.count { it * a >= 40000000 }

    println(amount)
}