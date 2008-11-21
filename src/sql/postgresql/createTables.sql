CREATE TABLE tmw_accounts 
( 
   id           SERIAL      PRIMARY KEY, 
   username     TEXT        NOT NULL UNIQUE, 
   password     TEXT        NOT NULL, 
   email        TEXT        NOT NULL, 
   level        SMALLINT    NOT NULL, 
   banned       SMALLINT    NOT NULL, 
   registration INTEGER     NOT NULL, 
   lastlogin    INTEGER     NOT NULL  
);

CREATE INDEX tmw_accounts_username ON tmw_accounts ( username );


CREATE TABLE tmw_characters 
(
   id           SERIAL      PRIMARY KEY,
   user_id      INTEGER     NOT NULL,
   name         TEXT        NOT NULL UNIQUE,
   gender       SMALLINT    NOT NULL,
   hair_style   SMALLINT    NOT NULL,
   hair_color   INTEGER     NOT NULL,
   level        INTEGER     NOT NULL,
   char_pts     INTEGER     NOT NULL,
   correct_pts  INTEGER     NOT NULL,
   money        INTEGER     NOT NULL,
   x            SMALLINT    NOT NULL,
   y            SMALLINT    NOT NULL,
   map_id       SMALLINT    NOT NULL,
   str          SMALLINT    NOT NULL,
   agi          SMALLINT    NOT NULL,
   dex          SMALLINT    NOT NULL,
   vit          SMALLINT    NOT NULL,
   int          SMALLINT    NOT NULL,
   will         SMALLINT    NOT NULL,
   unarmed_exp  INTEGER     NOT NULL,
   knife_exp    INTEGER     NOT NULL,
   sword_exp    INTEGER     NOT NULL,
   polearm_exp  INTEGER     NOT NULL,
   staff_exp    INTEGER     NOT NULL,
   whip_exp     INTEGER     NOT NULL,
   bow_exp      INTEGER     NOT NULL,
   shoot_exp    INTEGER     NOT NULL,
   mace_exp     INTEGER     NOT NULL,
   axe_exp      INTEGER     NOT NULL,
   thrown_exp   INTEGER     NOT NULL,
   --
   FOREIGN KEY (user_id) REFERENCES tmw_accounts(id)
);

CREATE TABLE tmw_inventories 
(
   id           SERIAL      PRIMARY KEY,
   owner_id     INTEGER     NOT NULL,
   slot         SMALLINT    NOT NULL,
   class_id     INTEGER     NOT NULL,
   amount       SMALLINT    NOT NULL,
   --
   FOREIGN KEY (owner_id) REFERENCES tmw_characters(id)
);

CREATE TABLE tmw_guilds 
(
   id           SERIAL      PRIMARY KEY,
   name 		TEXT        NOT NULL UNIQUE
);

CREATE TABLE tmw_guild_members 
(
   guild_id     INTEGER     NOT NULL,
   member_id    INTEGER     NOT NULL,
   rights       INTEGER     NOT NULL,
   --
   FOREIGN KEY (guild_id)  REFERENCES tmw_guilds(id),
   FOREIGN KEY (member_id) REFERENCES tmw_characters(id)
);

CREATE INDEX tmw_guild_members_g ON tmw_guild_members ( guild_id );
CREATE INDEX tmw_guild_members_m ON tmw_guild_members ( member_id );

CREATE TABLE tmw_quests 
(
   owner_id     INTEGER     NOT NULL,
   name         TEXT        NOT NULL,
   value        TEXT        NOT NULL,
   --
   FOREIGN KEY (owner_id) REFERENCES tmw_characters(id)
);

CREATE TABLE tmw_world_states 
( 
   state_name   TEXT        PRIMARY KEY, 
   map_id       INTEGER     NULL, 
   value        TEXT        NULL, 
   moddate      INTEGER     NOT NULL 
);

INSERT INTO "tmw_world_states" VALUES('accountserver_startup',NULL,NULL,1221633910);
INSERT INTO "tmw_world_states" VALUES('accountserver_version',NULL,NULL,1221633910);

