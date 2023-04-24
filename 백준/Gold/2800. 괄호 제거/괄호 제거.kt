import java.util.*
import kotlin.collections.ArrayList

var answers = TreeSet<String>()
var pairs = ArrayList<Pair<Int, Int>>()
var line = ""


fun getExpr(exceptList : List<Int>) : String {
    val sb = StringBuilder()
    repeat(line.length) {
        if(it !in exceptList) sb.append(line[it])
    }
    return sb.toString()
}

fun selectPairs(idx: Int, selected: ArrayList<Int>) {
    if(idx == pairs.size) return
    
    answers.add(getExpr(selected))
    selectPairs(idx+1, selected)
    
    selected.add(pairs[idx].first)
    selected.add(pairs[idx].second)
    answers.add(getExpr(selected))
    selectPairs(idx+1, selected)
    selected.removeLast()
    selected.removeLast()
    
}

fun main() {
    line = readln()
    val st = LinkedList<Int>()
    
    line.forEachIndexed { idx, c ->
        when(c) {
            '(' -> st.push(idx)
            ')' -> pairs.add(Pair(st.pop(), idx))
        }
    }
    selectPairs(0, ArrayList())
    val sb = StringBuilder()
    answers.forEachIndexed { idx, it ->
        if(idx!=0) sb.appendLine(it)
    }
    println(sb.toString())
}