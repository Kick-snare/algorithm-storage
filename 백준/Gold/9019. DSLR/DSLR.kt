
import java.util.*

data class Regisiter(
    val d1: Int, val d2: Int, val d3: Int, val d4: Int
) {
    constructor(value: Int): this(value/1000, (value/100)%10, (value/10)%10, value%10)
    val value get() = d1*1000 + d2*100 + d3*10 + d4
    fun doubled() = Regisiter((value * 2) % 10000)
    fun subtracted() = Regisiter(if(value==0) 9999 else value-1)
    fun lefted() = Regisiter(d2, d3, d4, d1)
    fun righted() = Regisiter(d4, d1, d2, d3)
}

fun main() {
    val sb = StringBuilder()
    repeat(readln().toInt()) {
        val (a, b) = readln().split(" ").map(String::toInt).map(::Regisiter)
        val q: Queue<Regisiter> = LinkedList<Regisiter>().apply{ add(a) }
        val visited = Array<Pair<Int, Int>?>(10000) { null }
        
        while(q.isNotEmpty()) {
            val reg = q.poll()
            
            if(reg.value == b.value) break
            
            sequenceOf(reg.doubled(), reg.subtracted(), reg.lefted(), reg.righted())
                .withIndex()
                .filter { visited[it.value.value] == null }
                .forEach { (operator, next) ->
                    visited[next.value] = operator to reg.value
                    q.add(next)
                }
        }
        val _sb = StringBuilder()
        var prev: Int = b.value
        while(true) {
            val (operator, regValue) = visited[prev] ?: break
            when(operator) {
                0 -> 'D'
                1 -> 'S'
                2 -> 'L'
                3 -> 'R'
                else -> break
            }.let { _sb.append(it) }
            prev = regValue
            if(regValue == a.value) break
        }
        sb.appendLine(_sb.reverse().toString())
    }
    print(sb.toString())
}