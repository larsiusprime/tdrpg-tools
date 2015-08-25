package;
import haxe.xml.Printer;

/**
 * ...
 * @author larsiusprime
 */
class FancyPrinter extends Printer
{

	public function new(pretty:Bool=true) 
	{
		super(pretty);
	}
	
	static public function print(xml:Xml, ?pretty = false) {
		var printer = new FancyPrinter(pretty);
		printer.writeNode(xml, "");
		return printer.output.toString();
	}
	
	override function writeNode(value:Xml, tabs:String) 
	{
		switch(value.nodeType) {
			case Element:
				write(tabs + "<");
				write(value.nodeName);
				
				var attNames = [];
				for (attribute in value.attributes())
				{
					attNames.push(attribute);
				}
				
				attNames.sort(alpha);
				
				for (attribute in attNames) {
					write(" " + attribute + "=\"");
					write(StringTools.htmlEscape(value.get(attribute), true));
					write("\"");
				}
				if (hasChildren(value)) {
					write(">");
					newline();
					for (child in value) {
						writeNode(child, pretty ? tabs + "\t" : tabs);
					}
					write(tabs + "</");
					write(value.nodeName);
					write(">");
					newline();
				} else {
					write("/>");
					newline();
				}
			default: super.writeNode(value, tabs);
		}
	}
	
	function alpha(a:String, b:String):Int
	{
		if (a < b) return -1;
		if (a > b) return 1;
		return 0;
	}
}