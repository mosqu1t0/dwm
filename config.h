/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 14;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */

static const char *fonts[]          = {

                    "JetBrains Mono:style=Bold:size=12",
                    "Apple Color Emoji:style=Regular",
					"WenQuanYi Micro Hei Mono:size=12:style=Bold:antialias=true:autohint=true",
					"Symbols Nerd Font:pixelsize=22:type=1000-em:antialias=true:autohint=true"

};
static const char dmenufont[]       = "JetBrains Mono:style=Bold:size=12";
static const char col_gray1[]       = "#24283b";
static const char col_gray2[]       = "#24283b";
static const char col_gray3[]       = "#c0caf5";
static const char col_gray4[]       = "#24283b";
static const char col_cyan[]        = "#f7768e";
static const unsigned int baralpha = 0xf0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "C", "D", "E", "F", "G", "A", "ﱘ", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "panel",    NULL,       NULL,       0,            1,           -1 },
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "jetbrains-idea",     NULL,       NULL,       0,            0,           -1 },
	{ "flameshot",NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "Tile",      tile },    /* first entry is default */
	{ "Float",      NULL },    /* no layout function means floating behavior */
	{ "Mono",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *slock[]  = { "slock", NULL };
static const char *voldown[]  = { "/home/mosquito/Software/dwm/sh/voldown.sh", NULL };
static const char *volup[]  = { "/home/mosquito/Software/dwm/sh/volup.sh", NULL };
static const char *voltoggle[]  = { "/home/mosquito/Software/dwm/sh/voltoggle.sh", NULL };
static const char *lightdown[]  = { "/home/mosquito/Software/dwm/sh/lightdown.sh", NULL };
static const char *lightup[]  = { "/home/mosquito/Software/dwm/sh/lightup.sh", NULL };
static const char *trayer[] = {"/home/mosquito/Software/dwm/sh/trayer.sh", NULL};
static const char *pic[] = {"flameshot", "gui", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             111,       spawn,          {.v = trayer} },//up
	{ MODKEY|ShiftMask,             38,        spawn,          {.v = pic} },//a
	{ MODKEY,                       116,       spawn,          {.v = lightdown} },//down
	{ MODKEY,                       111,       spawn,          {.v = lightup} },//up
	{ MODKEY,                       113,       spawn,          {.v = voldown} },//left
	{ MODKEY,                       114,       spawn,          {.v = volup} },//right
	{ MODKEY|ShiftMask,             113,       spawn,          {.v = voltoggle} },//left
	{ MODKEY,                       24,        spawn,          {.v = dmenucmd } },//q
	{ MODKEY|ShiftMask,             36,        spawn,          {.v = termcmd } },//return
	{ MODKEY|ShiftMask,             30,        spawn,          {.v = slock } },//l
	{ MODKEY,                       56,        togglebar,      {0} },//b
	{ MODKEY,                       44,        focusstack,     {.i = +1 } },//n
	{ MODKEY,                       45,        focusstack,     {.i = -1 } },//e
	{ MODKEY,                       57,        incnmaster,     {.i = +1 } },//k
	{ MODKEY,                       58,        incnmaster,     {.i = -1 } },//m
	{ MODKEY,                       43,        setmfact,       {.f = -0.05} },//h
	{ MODKEY,                       46,        setmfact,       {.f = +0.05} },//i
	{ MODKEY,                       36,        zoom,           {0} },//return
	{ MODKEY,                       23,        view,           {0} },//tab
	{ MODKEY|ShiftMask,             54,        killclient,     {0} },//c
	{ MODKEY,                       41,        setlayout,      {.v = &layouts[0]} },//t
	{ MODKEY,                       26,        setlayout,      {.v = &layouts[1]} },//f
	{ MODKEY,                       55,        setlayout,      {.v = &layouts[2]} },//v
	{ MODKEY|ShiftMask,             26,        fullscreen,     {0} },//f
	{ MODKEY,                       65,        setlayout,      {0} },
	{ MODKEY|ShiftMask,             65,        togglefloating, {0} },//space
	{ MODKEY,                       19,        view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             19,        tag,            {.ui = ~0 } },
	{ MODKEY,                       59,        focusmon,       {.i = -1 } },      // comma
	{ MODKEY,                       60,        focusmon,       {.i = +1 } },      // period
	{ MODKEY|ShiftMask,             59,        tagmon,         {.i = -1 } },      // comma
	{ MODKEY|ShiftMask,             60,        tagmon,         {.i = +1 } },      // period

	{ MODKEY|ShiftMask,             44,        rotatetags,     {.i = -1 } },//n
	{ MODKEY|ShiftMask,             45,        rotatetags,     {.i = +1 } },//e
	{ MODKEY,                       20,        setgaps,        {.i = -1 } },//-
	{ MODKEY,                       21,        setgaps,        {.i = +1 } },//=
	{ MODKEY|ShiftMask,             21,        setgaps,        {.i = 0  } },//=
	TAGKEYS(                10,                    0)                 // 1
	TAGKEYS(                11,                    1)                 // 2
	TAGKEYS(                12,                    2)                 // 3
	TAGKEYS(                13,                    3)                 // 4
	TAGKEYS(                14,                    4)                 // 5
	TAGKEYS(                15,                    5)                 // 6
	TAGKEYS(                16,                    6)                 // 7
	TAGKEYS(                17,                    7)                 // 8
	TAGKEYS(                18,                    8)                 // 9
	{ MODKEY|ShiftMask,     24,    quit,           {0} },             // q
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

