use db20178057;

-- a) Create a View called Client_View1 having all data of Client table.
CREATE VIEW Client_View1 AS SELECT * FROM client;
SELECT * FROM Client_View1;

-- b) Create a view called Client_vw2 having Client_ID , city and Bal_Due attributes of client table.
CREATE VIEW Client_vw2 AS SELECT client_id, city, bal_due FROM client;
SELECT * FROM Client_vw2;

-- c) Create a view called Client_vw3 with renaming Client_ID as CID , Client_Name as cname and Address as Addr of client table.
CREATE VIEW Client_vw3 AS SELECT client_id AS CID, client_name AS cname, address AS Addr FROM client;
SELECT * FROM Client_vw3;

-- d) Using Client_view1, print client_name and Balance of Client whose ID is ‘cn01001’.
SELECT client_name, bal_due FROM Client_View1 WHERE client_id = 'cn01001';

-- e) Insert a row into Client_vw2 (‘cn02003’, ‘alld’, 5000).
INSERT INTO Client_vw2 VALUES ('cn02003', 'alld', 5000);
SELECT * FROM Client_vw2;

-- f) Modify view Client_vw2 such that bal_due of Client_ID CN01004 now become 1000.
UPDATE Client_vw2 SET bal_due = 1000 WHERE client_id = 'cn01004';
SELECT * FROM Client_vw2;

-- g) Delete row from view client_vw2 where Client_ID=’CN02003’.
DELETE FROM Client_vw2 WHERE client_id = 'cn02003';
SELECT * FROM Client_vw2;

-- h) Delete view client_vw3 from memory.
DROP VIEW client_vw3;

-- i) Consider another table Client2 (ClientID, Phone). Create a view client_vw4 which has clientID, Client_name, bal_due and phone. Use both The tables Client and Client2
-- CREATE TABLE Client2 (
-- Client_ID VARCHAR(10) NOT NULL,
-- Phone VARCHAR(10),
-- PRIMARY KEY(Client_ID)
-- );
-- INSERT INTO Client2 VALUES ('cn01001', '1234567890');
-- INSERT INTO Client2 VALUES ('cn01002', '2345678901');
-- INSERT INTO Client2 VALUES ('cn01003', '3456789012');
-- INSERT INTO Client2 VALUES ('cn01004', '4567890123');
-- INSERT INTO Client2 VALUES ('cn01005', '5678901234');
-- INSERT INTO Client2 VALUES ('cn01006', '6789012345');
-- INSERT INTO Client2 VALUES ('cn01007', '7890123456');
-- INSERT INTO Client2 VALUES ('cn01008', '8901234567');
-- INSERT INTO Client2 VALUES ('cn01009', '9012345678');
-- INSERT INTO Client2 VALUES ('cn01010', '0123456789');
-- INSERT INTO Client2 VALUES ('cn01011', '1234554321');
CREATE VIEW client_vw4 AS SELECT c1.client_id, c1.client_name, c1.bal_due, c2.Phone FROM client AS c1 JOIN Client2 AS c2 ON c1.client_id = c2.Client_ID;
SELECT * FROM client_vw4;

