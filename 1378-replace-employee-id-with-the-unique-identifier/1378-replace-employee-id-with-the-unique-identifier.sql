# Write your MySQL query statement below
select ei.unique_id,e.name from Employees e LEFT JOIN EmployeeUNI ei
using(id) 