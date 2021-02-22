SELECT
	c_mktsegment, count(c_mktsegment)
FROM
	customer
GROUP BY
	c_mktsegment;
