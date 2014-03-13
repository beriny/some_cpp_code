<pre class="prettyprint lang-cpp">/*
 * 将s中的字符串按照字典顺序，降序排列
 */

#include &lt;iostream&gt;
#include &lt;set&gt;
#include &lt;functional&gt;
#include &lt;string&gt;

using namespace std;

template &lt;typename T&gt;
void printCollection(const T&amp; t)
{
	typename T::const_iterator itr;
	for ( itr = t.begin(); itr != t.end(); ++itr)
	{
		cout &lt;&lt; *itr &lt;&lt; " ";
	}
	cout &lt;&lt; endl;
}

int main(void)
{
	typedef greater&lt;string&gt; greater_str;
	
	set&lt;string, greater_str&gt; s;
	string str;
	
	int i=0;
	const int Size = 10;
	
	while (cin &gt;&gt; str &amp;&amp; i &lt; Size)
	{
		i++;	
		s.insert(str);
	}
	
	printCollection(s);
	
	return 0;
}

</pre>
<br />
