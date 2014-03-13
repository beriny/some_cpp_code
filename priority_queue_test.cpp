<pre class="prettyprint lang-cpp">/*
 * priority_queue 是STL中的优先队列
 */
 
#include &lt;queue&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;vector&gt;
#include &lt;functional&gt;

using namespace std;

template &lt;class T&gt;
void Output(const string&amp; name, T&amp; t)
{
	cout &lt;&lt; name &lt;&lt; ":" &lt;&lt; endl;
	while (!t.empty())
	{
		cout &lt;&lt; t.top() &lt;&lt; " ";
		t.pop();
	}
	cout &lt;&lt; endl;
}

int main(void)
{
	typedef vector&lt;int&gt; vector_int;
	typedef greater&lt;int&gt; greater_int;
	typedef less&lt;int&gt; less_int;
	
	priority_queue&lt;int, vector_int,  greater_int&gt; minPQ;
	priority_queue&lt;int, vector_int, less_int&gt;     maxPQ;
	
	int element;
	
	while (cin &gt;&gt; element)
	{
		minPQ.push(element);
		maxPQ.push(element);
	}
	
	Output("minPQ", minPQ);
	Output("maxPQ", maxPQ);
	
	return 0;
}</pre>
<br />
