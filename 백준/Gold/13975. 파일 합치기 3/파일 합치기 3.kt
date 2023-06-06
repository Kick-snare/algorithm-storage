import java.util.*

fun main() {
    val sb = StringBuilder()
    val t = readln().toInt()
    repeat(t) {
        val k = readln().toInt()
        val pq = PriorityQueue<Long>()
        readln().split(" ").asSequence().map(String::toLong).forEach(pq::add)
        
        var sum = 0L
        while(pq.size > 1) {
            val nf = pq.poll() + pq.poll()
            sum += nf
            pq.add(nf)
        }
        sb.appendLine(sum)
    }
    print(sb.toString())
}