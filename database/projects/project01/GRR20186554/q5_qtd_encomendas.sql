SELECT 
	n_name, count(c_custkey) 
FROM 
	nation JOIN customer 
ON 
	n_nationkey == c_nationkey 
JOIN
	orders
ON	
	o_custkey == c_custkey
GROUP BY 
	n_name
ORDER BY 
	count(c_custkey)
DESC;	
