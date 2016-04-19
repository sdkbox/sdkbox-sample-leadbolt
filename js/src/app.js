
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        // var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
        //     cc.log("QUIT");
        // });
        // var menu = new cc.Menu(quit);
        // var size = quit.getContentSize();
        // menu.x = winsize.width - size.width / 2 - 16;
        // menu.y = size.height / 2 + 16;
        // this.addChild(menu);

        return true;
    },

    createTestMenu:function() {
        sdkbox.PluginLeadBolt.init();
        sdkbox.PluginLeadBolt.setListener({
            onModuleLoaded: function(placement) {
                cc.log("onModuleLoaded: " + placement);
            },
            onModuleClosed: function(placement) {
                cc.log("onModuleClosed: " + placement);
            },
            onModuleClicked: function(placement) {
                cc.log("onModuleClicked: " + placement);
            },
            onModuleCached: function(placement) {
                cc.log("onModuleCached: " + placement);
            },
            onModuleFailed: function(placement, error, cached) {
                cc.log("onModuleFailed: " + placement + ", error: " + error + ", cached: " + (cached ? "YES" : "NO"));
            },
            onMediaFinished: function(viewCompleted) {
                cc.log("onMediaFinished: " + placement);
            }
        })

        var menu = new cc.Menu();
        var item1 = new cc.MenuItemLabel(new cc.LabelTTF("cache ad", "sans", 28), function() {
            cc.log("cache ad");
            sdkbox.PluginLeadBolt.loadModuleToCache("ad1");
        });
        menu.addChild(item1);

        var item2 = new cc.MenuItemLabel(new cc.LabelTTF("show ad", "sans", 28), function() {
            cc.log("show ad");
            if (sdkbox.PluginLeadBolt.isAdReady("ad1")) {
                sdkbox.PluginLeadBolt.loadModule("ad1");
            } else {
                cc.log("leadbolt ad is not ready");
            }
        });
        menu.addChild(item2);

        var winsize = cc.winSize;
        menu.x = winsize.width / 2;
        menu.y = winsize.height / 2;
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

