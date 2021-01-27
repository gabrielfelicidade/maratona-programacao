import java.util.*

fun main(args: Array<String>) {
    val sc = Scanner(System.`in`);

    val n = sc.nextInt()

    println((n downTo 1).reduce { acc, i -> acc * i })
}