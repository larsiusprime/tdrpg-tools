package;

import haxe.ui.HaxeUIApp;
import haxe.ui.Toolkit;
import haxe.ui.components.Button;
import haxe.ui.core.Component;
import haxe.ui.core.Screen;
import haxe.ui.macros.ComponentMacros;

class Main {
    public static function main() {
        var app = new HaxeUIApp();
        app.ready(function() {
            #if kha
            var main:Component = ComponentMacros.buildComponent("../assets/ui/main.xml");
            #else
            var main:Component = ComponentMacros.buildComponent("assets/ui/main.xml");
            #end

            app.addComponent(main);

            var button:Button = main.findComponent("testButton2", null, true);
            button.onClick = function(e) {
                button.text = "Set from code!";
            }

            app.start();
        });
    }
}
