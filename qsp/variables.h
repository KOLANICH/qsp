/* Copyright (C) 2005-2010 Valeriy Argunov (nporep AT mail DOT ru) */
/*
* This library is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2.1 of the License, or
* (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include "declarations.h"
#include "variant.h"

#ifndef QSP_VARSDEFINES
    #define QSP_VARSDEFINES

    #define QSP_VARSSEEK 50
    #define QSP_VARSCOUNT 256 * QSP_VARSSEEK
    #define QSP_VARARGS QSP_FMT("ARGS")
    #define QSP_VARRES QSP_FMT("RESULT")

    typedef struct
    {
        int Num;
        QSPString Str;
    } QSPVarValue;

    typedef struct
    {
        int Index;
        QSPString Str;
    } QSPVarIndex;

    typedef struct
    {
        QSPString Name;
        QSPVarValue *Values;
        int ValsCount;
        QSPVarIndex *Indices;
        int IndsCount;
        int IndsBufSize;
    } QSPVar;

    typedef struct
    {
        QSPVar *Vars;
        int VarsCount;
    } QSPVarsGroup;

    extern QSPVar qspVars[QSP_VARSCOUNT];
    extern QSPVarsGroup *qspSavedVarsGroups;
    extern int qspSavedVarsGroupsCount;

    /* External functions */
    void qspClearVars(QSP_BOOL);
    void qspEmptyVar(QSPVar *);
    QSPVar *qspVarReference(QSPString name, QSP_BOOL isCreate);
    QSPVar *qspVarReferenceWithType(QSPString name, QSP_BOOL isCreate, QSP_BOOL *isString);
    void qspSetVarValueByReference(QSPVar *, int, QSPVariant *);
    QSPVariant qspGetVarValueByReference(QSPVar *, int, QSP_BOOL);
    QSPString qspGetVarStrValue(QSPString name);
    int qspGetVarNumValue(QSPString name);
    QSPVariant qspGetVar(QSPString name);
    void qspPrepareGlobalVars();
    int qspPrepareLocalVars(QSPVar **);
    void qspRestoreLocalVars(QSPVar *, int, QSPVarsGroup *, int);
    void qspClearLocalVars(QSPVar *, int);
    void qspRestoreVarsList(QSPVar *, int);
    void qspClearVarsList(QSPVar *, int);
    int qspArraySize(QSPString name);
    int qspArrayPos(QSPString varName, QSPVariant *val, int ind, QSP_BOOL isRegExp);
    QSPVariant qspArrayMinMaxItem(QSPString name, QSP_BOOL isMin);
    int qspGetVarsCount();
    void qspSetArgs(QSPVar *, QSPVariant *, int);
    void qspApplyResult(QSPVar *, QSPVariant *);
    void qspMoveVar(QSPVar *, QSPVar *);
    /* Statements */
    void qspStatementSetVarValue(QSPString s);
    void qspStatementLocal(QSPString s);
    QSP_BOOL qspStatementCopyArr(QSPVariant *args, int count, QSPString *jumpTo, int extArg);
    QSP_BOOL qspStatementKillVar(QSPVariant *args, int count, QSPString *jumpTo, int extArg);

#endif
