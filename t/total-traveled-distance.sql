SELECT Users.user_id, name, IFNULL(SUM(distance), 0) AS `traveled distance`
FROM Users LEFT JOIN Rides ON Users.user_id = Rides.user_id
GROUP BY user_id ORDER BY user_id
