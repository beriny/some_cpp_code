<pre class="prettyprint lang-cpp">#include &lt;iostream&gt;
#include &lt;vector&gt;
#include &lt;algorithm&gt;

using namespace std;

const int ten = 10;

bool compare(const int&amp; a, const int&amp; b)
{
	return a%ten &gt; b%ten;
}

int main(void)
{
	vector&lt;int&gt; num;
	int element;
	
	while (cin &gt;&gt; element)
	{
		num.push_back(element);
	}
	
	sort(num.begin(), num.end(), compare);
	
	for (unsigned int i = 0; i &lt; num.size(); i += 1)
	{
		cout &lt;&lt; num[i] &lt;&lt; " ";
	}
	cout &lt;&lt; endl;
	
	return 0;
}</pre>
<br />
