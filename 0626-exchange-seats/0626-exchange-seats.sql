SELECT
    CASE
        WHEN id % 2 = 1 THEN LEAD(id, 1, id) OVER (ORDER BY id)
        ELSE id - 1
    END AS id,
    student
FROM Seat
ORDER BY id;