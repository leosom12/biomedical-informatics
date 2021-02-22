SELECT 
    count(*) 
FROM 
    (
        SELECT c_custkey FROM customer
        EXCEPT
        SELECT c_custkey FROM customer, orders 
        WHERE c_custkey == o_custkey 
        AND o_comment LIKE '%special request%'
    )
;
