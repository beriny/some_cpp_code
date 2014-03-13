<pre class="prettyprint lang-cpp">#include &lt;stack&gt;
#include &lt;iostream&gt;
#include &lt;vector&gt;

using namespace std;

int main(void)
{
	typedef vector&lt;int&gt; int_vector;
	stack&lt;int, int_vector&gt; s;
	
	int element;
	
	while (cin &gt;&gt; element)
	{
		s.push(element);
	}
	
	cout &lt;&lt; "Contents are:" &lt;&lt; endl;
	for ( ;  !s.empty() ;  s.pop() )
	{
		cout &lt;&lt; s.top() &lt;&lt; endl;
	}
	
	return 0;
}</pre>
<br />
