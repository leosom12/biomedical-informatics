SELECT 
	n_name, 
	sum(l_quantity) as ITENS 

FROM 
	customer,
	orders,
	lineitem,
	nation

WHERE
	c_custkey = o_custkey
	and n_nationkey = c_nationkey 
	and l_orderkey = o_orderkey

GROUP BY
	n_name	

ORDER BY
	itens

DESC		

LIMIT
	10;
