/*
 *  The Mana World Server
 *  Copyright 2004 The Mana World Development Team
 *
 *  This file is part of The Mana World.
 *
 *  The Mana World  is free software; you can redistribute  it and/or modify it
 *  under the terms of the GNU General  Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or any later version.
 *
 *  The Mana  World is  distributed in  the hope  that it  will be  useful, but
 *  WITHOUT ANY WARRANTY; without even  the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 *  more details.
 *
 *  You should  have received a  copy of the  GNU General Public  License along
 *  with The Mana  World; if not, write to the  Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 *  $Id$
 */

#ifndef _TMWSERV_CHARACTER_HPP_
#define _TMWSERV_CHARACTER_HPP_

#include <string>
#include <vector>

#include "common/inventorydata.hpp"
#include "game-server/being.hpp"

class BuySell;
class GameClient;
class MessageIn;
class MessageOut;
class Point;
class Trade;

/**
 * The representation of a player's character in the game world.
 */
class Character : public Being
{
    public:

        /**
         * Utility constructor for creating a Character from a received
         * characterdata message.
         */
        Character(MessageIn &msg);

        /**
         * Perform actions.
         */
        void perform();

        /**
         * Gets client computer.
         */
        GameClient *getClient() const
        { return mClient; }

        /**
         * Sets client computer.
         */
        void setClient(GameClient *c)
        { mClient = c; }

        /**
         * Gets a reference on the possessions.
         */
        Possessions const &getPossessions() const
        { return mPossessions; }

        /**
         * Gets a reference on the possessions.
         */
        Possessions &getPossessions()
        { return mPossessions; }

        /**
         * Gets the Trade object the character is involved in.
         */
        Trade *getTrading() const;

        /**
         * Sets the Trade object the character is involved in.
         * Cancels other transactions.
         */
        void setTrading(Trade *t);

        /**
         * Gets the BuySell object the character is involved in.
         */
        BuySell *getBuySell() const;

        /**
         * Sets the trade object the character is involved in.
         * Cancels other transactions.
         */
        void setBuySell(BuySell *t);

        /**
         * Cancels current transaction.
         */
        void cancelTransaction();

        /**
         * Gets transaction status of the character.
         */
        bool isBusy() const
        { return mTransaction != TRANS_NONE; }

        /*
         * Character data:
         * Get and set methods
         */

        /** Gets the database id of the character. */
        int
        getDatabaseID() const
        { return mDatabaseID; }

        /** Sets the database id of the character. */
        void
        setDatabaseID(int id)
        { mDatabaseID = id; }

        /** Gets the name of the character. */
        std::string const &
        getName() const
        { return mName; }

        /** Sets the name of the character. */
        void
        setName(const std::string& name)
        { mName = name; }

        /** Gets the gender of the character (male or female). */
        int
        getGender() const
        { return mGender; }

        /** Sets the gender of the character (male or female). */
        void
        setGender(int gender)
        { mGender = gender; }

        /** Gets the hairstyle of the character. */
        int
        getHairStyle() const
        { return mHairStyle; }

        /** Sets the hairstyle of the character. */
        void
        setHairStyle(int style)
        { mHairStyle = style; }

        /** Gets the haircolor of the character. */
        int
        getHairColor() const
        { return mHairColor; }

        /** Sets the haircolor of the character. */
        void
        setHairColor(int color)
        { mHairColor = color; }

        /** Gets the level of the character. */
        int
        getLevel() const
        { return mLevel; }

        /** Sets the level of the character. */
        void
        setLevel(int level)
        { mLevel = level; }

        /** Gets the account level of the user. */
        int getAccountLevel() const
        { return mAccountLevel; }

        /** Sets the account level of the user. */
        void setAccountLevel(int l)
        { mAccountLevel = l; }

        /**
         * Sends a message that informs the client about attribute
         * modified since last call.
         */
        void sendStatus();

        /**
         * Gets the ID of the map that the character is on.
         * For serialization purpose only.
         */
        int getMapId() const;

        /**
         * Sets the ID of the map that the character is on.
         * For serialization purpose only.
         */
        void setMapId(int);

        /**
         * Updates base Being attributes.
         */
        void modifiedAttribute(int);

    private:
        Character(Character const &);
        Character &operator=(Character const &);

        /**
         * Marks attribute as recently modified.
         */
        void flagAttribute(int);

        enum TransactionType
        { TRANS_NONE, TRANS_TRADE, TRANS_BUYSELL };

        GameClient *mClient;   /**< Client computer. */
        /** Handler of the transaction the character is involved in. */
        void *mTransactionHandler;

        Possessions mPossessions;    /**< Possesssions of the character. */

        /** Attributes modified since last update. */
        std::vector< unsigned char > mModifiedAttributes;

        std::string mName;           /**< Name of the character. */
        int mDatabaseID;             /**< Character's database ID. */
        unsigned char mGender;       /**< Gender of the character. */
        unsigned char mHairStyle;    /**< Hair Style of the character. */
        unsigned char mHairColor;    /**< Hair Color of the character. */
        unsigned char mLevel;        /**< Level of the character. */
        unsigned char mAccountLevel; /**< Account level of the user. */
        TransactionType mTransaction; /**< Trade/buy/sell action the character is involved in. */
};

#endif // _TMWSERV_CHARACTER_HPP_
