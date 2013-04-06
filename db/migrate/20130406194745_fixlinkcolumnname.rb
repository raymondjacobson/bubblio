class Fixlinkcolumnname < ActiveRecord::Migration
  def up
  	rename_column :links, :hash, :link_hash
  end

  def down
  end
end
