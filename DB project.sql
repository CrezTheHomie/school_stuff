select * from MEMBEROFTEST
order by HRHHID,QSTNUM asc;

create table MEMBER_OF
(PULINENO	NUMERICAL not null,
HRHHID	varchar(15) not null,
Primary key(PULINENO, household),
Foreign key(PULINENO) references person(PULINENO),
Foreign key(HRHHID) references household(HRHHID)
);