fun main() {
    val sb = StringBuilder()
    val dq = ArrayDeque<String>()
    repeat(readln().toInt()) {
        val cmd = readln().split(' ')
        when (cmd[0]) {
            "push_front" -> dq.addFirst(cmd[1])
            "push_back" -> dq.addLast(cmd[1])
            "pop_front" -> dq.removeFirstOrNull()
            "pop_back" -> dq.removeLastOrNull()
            "empty" -> if (dq.isEmpty()) 1 else 0
            "front" -> dq.firstOrNull()
            "back" -> dq.lastOrNull()
            "size" -> dq.size
            else -> {}
        }.let { if(it !is Unit) sb.appendLine(it ?: "-1") }
    }
    print(sb)
}